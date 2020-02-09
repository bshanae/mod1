#include "water.h"

using namespace		mod1_algorithm;

float				water::read_water_depth(const point2<int> &iter)
{
	return (water_data[data_size.x * iter.y + iter.x]);
}

void				water::write_water_depth(const point2<int> &iter, const float &value)
{
	water_data[data_size.x * iter.y + iter.x] = value;
}

void				water::increment_water_depth(const point2<int> &iter, const float &value)
{
	water_data[data_size.x * iter.y + iter.x] += value;
}
