#include "water.h"

using namespace			mod1_algorithm;

float					water::read_terrain_height(const point2<int> &iter)
{
	return (terrain_data[data_size.x * iter.y + iter.x]);
}

float					water::read_total_height(const point2<int> &iter)
{
	return (read_terrain_height(iter) + read_water_depth(iter));
}
