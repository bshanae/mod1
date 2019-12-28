#include "mod1_water.h"

void					mod1_water::gravity_helper_a(const mod1_point2<int> &iter)
{
	mod1_point2<int>	second;

	second = mod1_point2<int>(iter.x + 1, iter.y);
	gravity_helper_b(iter, second);

	second = mod1_point2<int>(iter.x - 1, iter.y);
	gravity_helper_b(iter, second);

	second = mod1_point2<int>(iter.x, iter.y + 1);
	gravity_helper_b(iter, second);

	second = mod1_point2<int>(iter.x, iter.y - 1);
	gravity_helper_b(iter, second);
}

void					mod1_water::gravity_helper_b(const mod1_point2<int> &from, const mod1_point2<int> &to)
{
	if (get_water(from) >= 1)
		return ;
	try
	{
		if (get_pressure(from) > get_pressure(to)) // TODO optimize by precalculating from' pressure
			replace_water(from, to);
	}
	catch (...)
	{

	}
}

void					mod1_water::gravity()
{
	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < 10; iter.y++)
		for (iter.x = 0; iter.x < 10; iter.x++)
			gravity_helper_a(iter);
	update_height();
}