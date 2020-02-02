#include "water.h"

using namespace			mod1_algorithm;

bool 					water::callback(int key, void *ptr)
{
	auto				water = (mod1_algorithm::water *)ptr;

#define PRESS_ONLY		1

#if PRESS_ONLY
	static int kostyl = 0;

	if (kostyl++ % 2 == 1)
		return (false);
#endif

	if (key == GLFW_KEY_1)
	{
		water->water_data.set(0);
		
#ifdef MOD1_WATER_FLOOD_BORDER
#define	HEIGHT			100
#define WIDTH			10

		point2<int>		iter;

		for (iter.y = 0; iter.y < water->data_size.y; iter.y++)
			for (iter.x = 0; iter.x < WIDTH; iter.x++)
				water->set_water_depth(iter, HEIGHT);
		for (iter.y = 0; iter.y < water->data_size.y; iter.y++)
			for (iter.x = water->data_size.x - WIDTH; iter.x < water->data_size.x; iter.x++)
				water->set_water_depth(iter, HEIGHT);

		for (iter.x = 0; iter.x < water->data_size.x; iter.x++)
			for (iter.y = 0; iter.y < WIDTH; iter.y++)
				water->set_water_depth(iter, HEIGHT);
		for (iter.x = 0; iter.x < water->data_size.x; iter.x++)
			for (iter.y = water->data_size.y - WIDTH; iter.y < water->data_size.y; iter.y++)
				water->set_water_depth(iter, HEIGHT);

		water->cl_arg_water_data.write();
#endif
	}
	else if (key == GLFW_KEY_2)
	{

#ifdef MOD1_WATER_FLOOD_POINT
#define A_X               	2
#define A_Y                	2

#define D_X               	1
#define D_Y               	1

#define Q					10

		for (int y = 0; y < D_Y; y++)
			for (int x = 0; x < D_X; x++)
				water->set_water_depth(point2<int>(A_X + x, A_Y + y), Q);

		water->cl_arg_water_data.write();
#endif

#ifdef MOD1_WATER_FLOOD_UNIFORM
#define STEP				50

		static float		level = water->terrain->final_min().z;

		if (level > water->terrain->final_max().z)
			return (false);
		for (iter.y = 0; iter.y < water->terrain->size().y; iter.y++)
			for (iter.x = 0; iter.x < water->terrain->size().x; iter.x++)
				if (water->get_total_height(iter) < level)
					water->water_depth[iter] += STEP;
		level += STEP;
#endif
	}
	else if (key == GLFW_KEY_3)
		;
	else
		return (false);
#ifndef MOD1_WATER_FLOOD_UNIFORM
	water->gravity();
#endif

	water->update_model();
	water->update_color();
	water->update(model_slot::point);
	water->update(model_slot::color);

	return (true);
}