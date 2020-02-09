#include "water.h"

using namespace			mod1_algorithm;

#define MOD1_WATER_FLOOD_POINT

void 					water::callback(const mod1_engine_gl::event &event, void *ptr)
{
	auto				water = (mod1_algorithm::water *)ptr;
	const auto			key = event.read_key();

	if (key == GLFW_KEY_1)
	{
		water->water_data.set(0);
		
#ifdef MOD1_WATER_FLOOD_BORDER
#define	HEIGHT			100
#define WIDTH			10

		point2<int>		iter;

		for (iter.y = 0; iter.y < water->data_size.y; iter.y++)
			for (iter.x = 0; iter.x < WIDTH; iter.x++)
				water->write_water_depth(iter, HEIGHT);
//		for (iter.y = 0; iter.y < water->data_size.y; iter.y++)
//			for (iter.x = water->data_size.x - WIDTH; iter.x < water->data_size.x; iter.x++)
//				water->write_water_depth(iter, HEIGHT);
//
//		for (iter.x = 0; iter.x < water->data_size.x; iter.x++)
//			for (iter.y = 0; iter.y < WIDTH; iter.y++)
//				water->write_water_depth(iter, HEIGHT);
//		for (iter.x = 0; iter.x < water->data_size.x; iter.x++)
//			for (iter.y = water->data_size.y - WIDTH; iter.y < water->data_size.y; iter.y++)
//				water->write_water_depth(iter, HEIGHT);

		water->cl_arg_water_data.write();
#endif
	}
	else if (key == GLFW_KEY_2)
	{

#ifdef MOD1_WATER_FLOOD_POINT
#define A_X               	5
#define A_Y                	5

#define D_X               	3
#define D_Y               	3

#define Q					100

		for (int y = 0; y < D_Y; y++)
			for (int x = 0; x < D_X; x++)
				water->increment_water_depth(point2<int>(A_X + x, A_Y + y), Q);

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
	{
		water->write_water_depth(point2<int>(10, 10), 2);
		water->cl_arg_water_data.write();
	}
	else if (key == GLFW_KEY_4)
		;
	else
		return ;
#ifndef MOD1_WATER_FLOOD_UNIFORM
	water->gravity();
#endif

//	water->update_model(true);
//	water->update_normal(true);
//	water->update_color(true);
}