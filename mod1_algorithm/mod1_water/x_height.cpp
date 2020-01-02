#include "mod1_water.h"

void					mod1_water::update_height_helper(const mod1_point2<int> &iter, const float &new_height)
{
	auto				ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);

	if (ptr[1] < new_height)
		ptr[1] = new_height;
}

void					mod1_water::update_height_iter(const mod1_point2<int> &iter)
{
	mod1_point2<int>	iter_plane;
	int 				water;
	float				height;

	water = get_water(iter);
	water = water ? water : -50;
	height = get_height(iter) + (float)water * water_drop_height;

	iter_plane = mod1_point2<int>(iter.x, iter.y);
	update_height_helper(iter_plane, height);

	iter_plane = mod1_point2<int>(iter.x + 1, iter.y);
	update_height_helper(iter_plane, height);

	iter_plane = mod1_point2<int>(iter.x, iter.y + 1);
	update_height_helper(iter_plane, height);

	iter_plane = mod1_point2<int>(iter.x + 1, iter.y + 1);
	update_height_helper(iter_plane, height);
}

void					mod1_water::update_height()
{
	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
			((float *)get_ptr(iter, mod1_model_data::slot_point))[1] = -10;
	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
			update_height_iter(iter);
}