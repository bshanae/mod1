#include "water.h"

using namespace			mod1_algorithm;

void					water::update_model(const bool &save)
{
	point2<int>			iter;
	float				new_height;

	for (iter.y = 0; iter.y < data_size.y; iter.y++)
		for (iter.x = 0; iter.x < data_size.x; iter.x++)
		{
			if ((new_height = read_water_depth(iter)) <= 0)
				new_height = MOD1_WATER_HIDDEN;
			else
			{
				new_height = new_height < MOD1_WATER_MINIMUN_LEVEL ? 0 : new_height;
				new_height += read_terrain_height(iter);
			}
			write_height(iter, new_height);
		}

	if (save)
		model::save(model_slot::point);
}