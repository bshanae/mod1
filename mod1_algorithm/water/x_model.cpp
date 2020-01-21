#include "water.h"

using namespace			mod1_algorithm;

void					water::update_model_helper_a(const point2<int> &iter)
{
	point2<int>			iter_plane;
	float				water;
	float				height;

	water = get_water_depth(iter);
	if (water < MOD1_WATER_EPSILON)
		water = MOD1_WATER_HIDDEN;
	height = get_terrain_height(iter) + water;

	iter_plane = point2<int>(iter.x, iter.y);
	update_model_helper_b(iter_plane, height);

	iter_plane = point2<int>(iter.x + 1, iter.y);
	update_model_helper_b(iter_plane, height);

	iter_plane = point2<int>(iter.x, iter.y + 1);
	update_model_helper_b(iter_plane, height);

	iter_plane = point2<int>(iter.x + 1, iter.y + 1);
	update_model_helper_b(iter_plane, height);
}

void					water::update_model_helper_b(const point2<int> &iter, const float &new_height)
{
	auto				old_height = read_height(iter);

	if (new_height > old_height)
		write_height(iter, new_height);
}

void					water::update_model()
{
	point2<int>			iter;

	for (iter.y = 0; iter.y < size().y; iter.y++)
		for (iter.x = 0; iter.x < size().x; iter.x++)
			write_height(iter, MOD1_WATER_HIDDEN);
	for (iter.y = 0; iter.y < terrain->size().y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
			update_model_helper_a(iter);

	update_normal();
}