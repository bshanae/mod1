#include "water.h"

using namespace			mod1_algorithm;

void					water::data_prepare()
{
	point2<int>			iter;

	constant_flow = MOD1_WATER_CONST_A * MOD1_WATER_CONST_g * (1.f / terrain->delta()) * MOD1_WATER_CONST_dt;
	constant_depth = MOD1_WATER_CONST_dt / (terrain->delta() * terrain->delta());
	constant_limit = terrain_range;

	data_size = terrain->size();

	terrain_data.allocate(data_size.x * data_size.y);

	for (iter.y = 0; iter.y < data_size.y; iter.y++)
		for (iter.x = 0; iter.x < data_size.x; iter.x++)
			terrain_data[data_size.x * iter.y + iter.x] = terrain->read_height(iter);

	water_data.allocate(data_size.x * data_size.y);

	for (iter.y = 0; iter.y < data_size.y; iter.y++)
		for (iter.x = 0; iter.x < data_size.x; iter.x++)
			water_data[data_size.x * iter.y + iter.x] = 0;

	empty_data.allocate(water_data.size());
	empty_data.set(0);
}