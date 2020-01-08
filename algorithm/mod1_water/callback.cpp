#include "mod1_water.h"

bool 					mod1_water::callback(int key, void *ptr)
{
	auto				water = (mod1_water *)ptr;
	mod1_point2<int>	iter;

	if (key == GLFW_KEY_1)
	{
		water->water_depth.set(0);
		
#ifdef MOD1_WATER_FLOOD_BORDER
#define	HEIGHT			500
#define WIDTH			100

		for (iter.y = 0; iter.y < water->size.y; iter.y++)
			for (iter.x = 0; iter.x < WIDTH; iter.x++)
				water->water_depth[iter] = HEIGHT;
		for (iter.y = 0; iter.y < water->size.y; iter.y++)
			for (iter.x = water->size.x - WIDTH - 2; iter.x < water->size.x - 2; iter.x++)
				water->water_depth[iter] = HEIGHT;

		for (iter.x = 0; iter.x < water->size.x - 2; iter.x++)
			for (iter.y = 0; iter.y < WIDTH; iter.y++)
				water->water_depth[iter] = HEIGHT;
		for (iter.x = 0; iter.x < water->size.x - 2; iter.x++)
			for (iter.y = water->size.y - WIDTH - 2; iter.y < water->size.y - 2; iter.y++)
				water->water_depth[iter] = HEIGHT;
#endif
	}
	else if (key == GLFW_KEY_2)
	{
		static int kostyl = 0;

		if (kostyl++ % 2 == 1)
			return (false);

#ifdef MOD1_WATER_FLOOD_POINT

#define A_X               	10
#define A_Y                	10

#define D_X               	10
#define D_Y               	10

#define Q					500

		for (int y = 0; y < D_Y; y++)
			for (int x = 0; x < D_X; x++)
				water->water_depth[mod1_point2<int>(A_X + x, A_Y + y)] = Q;
#endif

#ifdef MOD1_WATER_FLOOD_UNIFORM
		static float		level = 0;

		if (level > water->terrain->max_raw.z)
			return (false);
		for (iter.y = 0; iter.y < water->terrain->size.y; iter.y++)
			for (iter.x = 0; iter.x < water->terrain->size.x; iter.x++)
				if (water->get_pressure(iter) < level)
					water->add_water(iter, 1);
		level += water->water_drop_height;
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
	water->upload_buffer(mod1_model_data::slot_point);
	water->upload_buffer(mod1_model_data::slot_color);

	return (true);
}