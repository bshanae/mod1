#include "mod1_map.h"

bool					mod1_map::model_write_height(const mod1_point2<int> &iter, const float &height)
{
	float				*ptr;
	try
	{
		ptr = model_get_ptr(iter, mod1_map::mod1_map_slot_point) + 1;
		if (*ptr < height)
			*ptr = height;
		return (true);
	}
	catch (mod1_map::exception_bad_coordinate &exception)
	{}
	return (false);
}

void					mod1_map::model_generate_hill(const mod1_point3<int> &summit)
{
	const auto			iter_const = model_find_ptr(summit);
	mod1_point2<int>	iter;
	float				height;
	bool 				at_least_one;
	const int 			step_limit = summit.z / model_delta;

	model_get_ptr(iter_const, mod1_map_slot_point)[1] = (float)summit.z;
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