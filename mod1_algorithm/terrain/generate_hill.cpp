#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::generate_hill_helper(const point2<int> &iter, const float &new_height)
{
	const float			old_height = read_height(iter);
	float				noise = 0;

#if MOD1_ENABLED(MOD1_TERRAIN_NOISE_HILL)
		noise = generate_noise(
			iter,
			MOD1_TERRAIN_NOISE_HILL_FREQUENCY,
			MOD1_TERRAIN_NOISE_HILL_RANGE,
			MOD1_TERRAIN_NOISE_HILL_OFFSET);
		noise *= pow(interpolate_cosine(0, 1, height / max_raw.z), MOD1_TERRAIN_NOISE_HILL_ADD);
#endif
		if ((new_height < 0 and old_height > new_height))
			write_height(iter, new_height + noise);
		else if (new_height > 0 and old_height < new_height)
			write_height(iter,
				old_height < 0 ?
				old_height / 2 + new_height  + noise :
				new_height + noise);
}

void					terrain::generate_hill_fix(const point2<int> &iter, const int &step)
{
	point2<int> 		iter_local[2];

	iter_local[0] = point2<int>(iter.x - step, iter.y - step);
	iter_local[1] = point2<int>(iter.x + step, iter.y + step);

	for (const auto &i : iter_local)
			if (get_cut_style(i) != cut_style::downwards)
				switch_cut_style(i);
}

void					terrain::generate_hill(const point3<double> &summit)
{
	const auto			iter_const = find_iter(summit);
	point2<int>			iter;
	float				height;
	const int 			step_limit = (int)(fabs((summit).z) / delta());

	generate_hill_helper(iter_const, (float)summit.z);
	for (int step = 1; step <= step_limit; step++)
	{
		height = interpolate_smooth(0, summit.z, ((float)(step_limit - step) / (float)step_limit));

		generate_hill_fix(iter_const, step);

		for (iter.x = iter_const.x - step + 1; iter.x <= iter_const.x + step - 1; iter.x++)
		{
			iter.y = iter_const.y - step;
			generate_hill_helper(iter, height);

			iter.y = iter_const.y + step;
			generate_hill_helper(iter, height);
		}

		for (iter.y = iter_const.y - step; iter.y <= iter_const.y + step; iter.y++)
		{
			iter.x = iter_const.x - step;
			generate_hill_helper(iter, height);

			iter.x = iter_const.x + step;
			generate_hill_helper(iter, height);
		}
	}
}