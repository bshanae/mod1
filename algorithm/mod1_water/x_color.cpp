#include "mod1_water.h"

void					mod1_water::update_color()
{
	mod1_point2<int>	iter;
	mod1_point3<float>	color;
	float 				total;
	float 				*ptr;

	return ;

	for (iter.y = 0; iter.y < terrain->size().y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
		{
			total = get_total_height(iter);
			for (int i = 0; i < 3; i++)
				color[i] = mod1_terrain::interpolate_cosine(
					mod1_point3<float>(MOD1_WATER_COLOR_A)[i],
					mod1_point3<float>(MOD1_WATER_COLOR_B)[i],
					total / MOD1_WATER_COLOR_RANGE);
//			ptr = (float *)get_ptr(iter, mod1_model_data::slot_color);
			for (int i = 0; i < 3; i++)
				ptr[i] = color[i];
		}
}