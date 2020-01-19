#include "water.h"

using namespace		mod1_algorithm;

float				water::get_terrain_height(const point2<int> &iter)
{
	return (terrain->read_height(iter));
}

float				water::get_water_depth(const point2<int> &iter)
{
	return (water_data[data_size.x * iter.y + iter.x]);
}

float				water::get_total_height(const point2<int> &iter)
{
	return (get_terrain_height(iter) + get_water_depth(iter));
}
