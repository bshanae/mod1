#include "mod1_water.h"

void 					mod1_water::build()
{
	set(terrain->min, terrain->max, terrain->delta);
	mod1_plane::build();

	mod1_point2<int>	iter;
	float				*ptr;

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			ptr[1] = -10;
		}

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_color);
			ptr[0] = 0;
			ptr[1] = 0;
			ptr[2] = 1;
		}

	iter.x = 9;
	iter.y = 9;
	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
	ptr[1] = 2;

	iter.x = 10;
	iter.y = 9;
	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
	ptr[1] = 2;

//	iter.x = 9;
//	iter.y = 10;
//	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
//	ptr[1] = 2;
//
//	iter.x = 10;
//	iter.y = 10;
//	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
//	ptr[1] = 2;
//
//	iter.x = 10;
//	iter.y = 11;
//	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
//	ptr[1] = 2;
//
//	iter.x = 9;
//	iter.y = 11;
//	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
//	ptr[1] = 2;
//
	water_level_grid.allocate(size.y - 1, size.x - 1);
	water_level_grid.set(0);

	height_grid.allocate(size.y - 1, size.x - 1);

	float const			*const_ptr;
	float				temp;

	for (int y = 0; y < size.y - 1; y++)
		for (int x = 0; x < size.x - 1; x++)
		{
			temp = 0;

			iter = mod1_point2<int>(x, y);
			const_ptr = (float const *)terrain->get_ptr(iter, mod1_model_data::slot_point);
			temp += *const_ptr;

			iter = mod1_point2<int>(x + 1, y);
			const_ptr = (float const *)terrain->get_ptr(iter, mod1_model_data::slot_point);
			temp += *const_ptr;

			iter = mod1_point2<int>(x, y + 1);
			const_ptr = (float const *)terrain->get_ptr(iter, mod1_model_data::slot_point);
			temp += *const_ptr;

			iter = mod1_point2<int>(x + 1, y + 1);
			const_ptr = (float const *)terrain->get_ptr(iter, mod1_model_data::slot_point);
			temp += *const_ptr;

			height_grid[y][x] = temp / 4;
		}

	for (int y = 0; y < size.y - 1; y++)
		for (int x = 0; x < size.x - 1; x++)
		{
			height_grid[y][x] = temp / 4;
		}
}