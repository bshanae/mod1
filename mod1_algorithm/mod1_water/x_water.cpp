#include "mod1_water.h"

void				mod1_water::replace_water(const mod1_point2<int> &from, const mod1_point2<int> &to, const int &volume)
{
	if (water_level[from.x][from.y] - volume <= 0)
		throw (exception_no_water());
	water_level[from.x][from.y]--;
	water_level[to.x][to.y]++;
}

void				mod1_water::add_water(const mod1_point2<int> &iter, const int &volume)
{
	water_level[iter.x][iter.y] += volume;
}