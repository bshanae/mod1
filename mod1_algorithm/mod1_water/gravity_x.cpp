#include "mod1_water.h"

void					mod1_water::gravity_one(const mod1_point2<int> &first)
{
	mod1_point2<int>	second;

	second = mod1_point2<int>(first.x + 1, first.y);
	gravity_two(first, second);

	second = mod1_point2<int>(first.x - 1, first.y);
	gravity_two(first, second);

	second = mod1_point2<int>(first.x, first.y + 1);
	gravity_two(first, second);

	second = mod1_point2<int>(first.x, first.y - 1);
	gravity_two(first, second);
}

void					mod1_water::gravity_two(const mod1_point2<int> &from, const mod1_point2<int> &to)
{
	if (get_water(from) >= 1)
		return ;
	try
	{
		if (get_pressure(from) > get_pressure(to)) // TODO optimize by precalculating from' pressure
		{
			remove_water(from);
			add_water(to);
		}
	}
	catch (...)
	{

	}
}

void					mod1_water::gravity()
{
	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
			gravity_one(iter);

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
			update_height(iter);
}