#include "mod1_water.h"

void				mod1_water::replace_water(const mod1_point2<int> &from, const mod1_point2<int> &to, const int &volume)
{
	int 			old_value[2];

	if (water_level[from.x][from.y] - volume <= 0)
		throw (exception_no_water());
	old_value[0] = water_level[from.x][from.y]--;
	old_value[1] = water_level[to.x][to.y]++;
#ifdef DEBUG
	printf("Replacing one unit from {%d, %d} to {%d, %d} : %d, %d -> %d, %d\n",
		from.x, from.y,
		to.x, to.y,
		old_value[0], old_value[1],
		water_level[from.x][from.y], water_level[to.x][to.y]);
#endif
}

void				mod1_water::add_water(const mod1_point2<int> &iter, const int &volume)
{
	water_level[iter.x][iter.y] += volume;
}

void				mod1_water::set_water(const mod1_point2<int> &iter, const int &volume)
{
	water_level[iter.x][iter.y] = volume;
}