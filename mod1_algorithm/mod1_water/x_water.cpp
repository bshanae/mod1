#include "mod1_water.h"

void					mod1_water::remove_water(const mod1_point2<int> &iter)
{
	water_level[iter.x][iter.y]--;
}

void					mod1_water::add_water(const mod1_point2<int> &iter)
{
	water_level[iter.x][iter.y]++;
}