#include "mod1_water.h"

void					mod1_water::update_height(const mod1_point2<int> &iter)
{
	mod1_point2<int>	iter_plane;
	float				height;

	height = get_pressure(iter);

	iter_plane = mod1_point2<int>(iter.x, iter.y);
	update_height_one(iter_plane, height);

	iter_plane = mod1_point2<int>(iter.x + 1, iter.y);
	update_height_one(iter_plane, height);

	iter_plane = mod1_point2<int>(iter.x, iter.y + 1);
	update_height_one(iter_plane, height);

	iter_plane = mod1_point2<int>(iter.x + 1, iter.y + 1);
	update_height_one(iter_plane, height);
}

void					mod1_water::update_height_one(const mod1_point2<int> &iter, const float &new_height)
{
	auto				ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);

	ptr[1] = new_height;
}

void 					mod1_water::build()
{
	set(
		terrain->min - mod1_point2<float>(terrain->delta / 2),
		terrain->max + mod1_point2<float>(terrain->delta / 2),
		terrain->delta);
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

//#define TEST

#ifdef TEST

#define A				2
#define B				3
#define H				2

	iter.x = A;
	iter.y = A;
	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
	ptr[1] = H;

	iter.x = A;
	iter.y = B;
	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
	ptr[1] = H;

	iter.x = B;
	iter.y = A;
	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
	ptr[1] = H;

	iter.x = B;
	iter.y = B;
	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
	ptr[1] = H;

#endif

	water_level.allocate(size.x, size.y);
	water_level.set(0);

	iter = mod1_point2<int>(2, 2);
	add_water(iter);
//	add_water(iter);

	gravity();
}