#include "water.h"

using namespace		mod1_algorithm;

void				water::set_water_depth(const point2<int> &iter, const float &value)
{
	water_data[data_size.x * iter.y + iter.x] = value;
}
