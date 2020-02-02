#include "water.h"

using namespace			mod1_algorithm;

void					water::update_color()
{
	point2<int>			iter;
	point3<float>		color;
	float 				total;

	for (iter.y = 0; iter.y < data_size.y; iter.y++)
		for (iter.x = 0; iter.x < data_size.x; iter.x++)
		{
			total = get_water_depth(iter);
			for (int i = 0; i < 3; i++)
				color[i] = terrain::interpolate_cosine(
					point3<float>(MOD1_WATER_COLOR_A)[i],
					point3<float>(MOD1_WATER_COLOR_B)[i],
					total / MOD1_WATER_COLOR_RANGE);
			write_color(iter, color);
		}
}