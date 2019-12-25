#include "mod1_terrain.h"

void					mod1_terrain::model_generate_hill(const mod1_point3<int> &summit)
{
	const auto			iter_const = model_find_ptr(summit);
	mod1_point2<int>	iter;
	float				height;
	bool 				at_least_one;
	const int 			step_limit = summit.z / model_delta;

	model_write_height(iter_const, (float)summit.z);
	for (int step = 1; step <= step_limit; step++)
	{
		height = model_interpolate_smooth(0, summit.z, ((float) (step_limit - step) / (float) step_limit));

		at_least_one = false;
		for (iter.x = iter_const.x - step; iter.x <= iter_const.x + step; iter.x++)
		{
			iter.y = iter_const.y - step;
			at_least_one = model_write_height(iter, height) || at_least_one;

			iter.y = iter_const.y + step;
			at_least_one = model_write_height(iter, height) || at_least_one;
		}
		for (iter.y = iter_const.y - step; iter.y <= iter_const.y + step; iter.y++)
		{
			iter.x = iter_const.x - step;
			at_least_one = model_write_height(iter, height) || at_least_one;

			iter.x = iter_const.x + step;
			at_least_one = model_write_height(iter, height) || at_least_one;
		}
		if (!at_least_one)
			break ;
	}
}