#include "mod1_water.h"

void					mod1_water::update_model_helper_a(const mod1_point2<int> &iter)
{
	mod1_point2<int>	iter_plane;
	float				water;
	float				height;

	water = water_depth[iter];
	if (water < MOD1_WATER_EPSILON)
		water = MOD1_WATER_HIDDEN;
	height = get_terrain_height(iter) + water;

	iter_plane = mod1_point2<int>(iter.x, iter.y);
	update_model_helper_b(iter_plane, height);

	iter_plane = mod1_point2<int>(iter.x + 1, iter.y);
	update_model_helper_b(iter_plane, height);

	iter_plane = mod1_point2<int>(iter.x, iter.y + 1);
	update_model_helper_b(iter_plane, height);

	iter_plane = mod1_point2<int>(iter.x + 1, iter.y + 1);
	update_model_helper_b(iter_plane, height);
}

void					mod1_water::update_model_helper_b(const mod1_point2<int> &iter, const float &new_height)
{
	auto				old_height = read_height(iter);

	if (old_height < new_height)
		write_height(iter, new_height);
}

void					mod1_water::update_model()
{
	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < size().y; iter.y++)
		for (iter.x = 0; iter.x < size().x; iter.x++)
			write_height(iter, -10);
	for (iter.y = 0; iter.y < terrain->size().y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
			update_model_helper_a(iter);
}