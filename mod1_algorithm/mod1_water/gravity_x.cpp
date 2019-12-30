#include "mod1_water.h"

bool					mod1_water::gravity_helper_a(const mod1_point2<int> &first)
{
	mod1_point2<int>	second;
	int					multiplier;
	int 				old_water_level = get_water(first);

	std::shuffle(direction_vector.begin(), direction_vector.end(), random_generator);
	for (const auto &direction : direction_vector)
	{
		multiplier = 0;
		while (true)
		{
			second = first + direction * multiplier++;
			if (multiplier >= old_water_level)
				break ;
			try
			{
				if (!get_water(second))
					break ;
			}
			catch (mod1_buffer<int>::exception_bad_index &exception)
			{
				break ;
			}
			catch (mod1_buffer2<int>::exception_bad_index &exception)
			{
				break ;
			}
		}

		for (multiplier--; multiplier > 0; multiplier--)
		{
			second = first + direction * multiplier;
			if (gravity_helper_b(first, second))
				return (true);
		}
		if (!get_water(first))
			break;
	}
	return (false);
}

bool				mod1_water::gravity_helper_b(const mod1_point2<int> &from, const mod1_point2<int> &to)
{
	try
	{
		if (get_water(from) - get_water(to) < 2)
			return (false);
		if (get_pressure(from) < get_pressure(to)) // TODO optimize by precalculating from' pressure
			return (false);
		replace_water(from, to);
		return (true);
	}
	catch (...)
	{
		return (false);
	}
}

void					mod1_water::gravity()
{
	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
			gravity_helper_a(iter);

	update_height();

#ifdef DEBUG
	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
	{
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
			printf("%d ", get_water(iter));
		printf("\n");
	}
	printf("\n");
#endif
}