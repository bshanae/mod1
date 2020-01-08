#include "mod1_terrain.h"

bool					mod1_terrain::generate_hill_helper(const mod1_point2<int> &iter, const float &height)
{
	float				noise = 0;
	float				*ptr;

	try
	{
		ptr = (float *)get_ptr(iter, mod1_model_data::slot_point) + 1;
#if MOD1_ENABLED(MOD1_TERRAIN_NOISE_HILL)
		noise = generate_noise(iter, MOD1_TERRAIN_NOISE_HILL_FREQUENCY, MOD1_TERRAIN_NOISE_HILL_RANGE);
		noise *= pow(interpolate_cosine(0, 1, height / max_raw.z), MOD1_TERRAIN_NOISE_HILL_ADD);
#endif
		if (*ptr < height)
			*ptr = height + noise;
		return (true);
	}
	catch (const mod1_plane::exception_coordinate &exception)
	{
		return (false);
	}
}

void					mod1_terrain::generate_hill(const mod1_point3<int> &summit)
{
	const auto			iter_const = find_ptr(summit);
	mod1_point2<int>	iter;
	float				height;
	bool 				at_least_one;
	const int 			step_limit = (int)(summit.z / delta);

	generate_hill_helper(iter_const, (float) summit.z);
	for (int step = 1; step <= step_limit; step++)
	{
		height = interpolate_smooth(0, summit.z, ((float)(step_limit - step) / (float)step_limit));

		at_least_one = false;
		for (iter.x = iter_const.x - step; iter.x <= iter_const.x + step; iter.x++)
		{
			iter.y = iter_const.y - step;
			at_least_one = generate_hill_helper(iter, height) || at_least_one;

			iter.y = iter_const.y + step;
			at_least_one = generate_hill_helper(iter, height) || at_least_one;
		}
		for (iter.y = iter_const.y - step; iter.y <= iter_const.y + step; iter.y++)
		{
			iter.x = iter_const.x - step;
			at_least_one = generate_hill_helper(iter, height) || at_least_one;

			iter.x = iter_const.x + step;
			at_least_one = generate_hill_helper(iter, height) || at_least_one;
		}
		if (!at_least_one)
			break ;
	}
}