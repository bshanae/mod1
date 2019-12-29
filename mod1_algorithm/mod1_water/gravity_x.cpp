#include "mod1_water.h"

void							mod1_water::gravity_helper_a(const mod1_point2<int> &iter)
{

	std::shuffle(direction_vector.begin(), direction_vector.end(), random_generator);

	for (const auto &direction : direction_vector)
		gravity_helper_b(iter, mod1_point2<int>(iter.x + direction.x, iter.y + direction.y));
}

void					mod1_water::gravity_helper_b(const mod1_point2<int> &from, const mod1_point2<int> &to)
{
	if (get_water(from) <= 1)
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

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
			gravity_helper_a(iter);
	update_height();
}