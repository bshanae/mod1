#include "mod1_water.h"

						mod1_water::mod1_water(mod1_terrain const *terrain) :
						terrain(terrain)
{

}

bool 					mod1_water::callback(int key, void *ptr)
{
	auto				water = (mod1_water *)ptr;
	mod1_point2<int>	iter;

	if (key == GLFW_KEY_1)
	{
		water->water_depth.set(0);
		
#ifdef FLOOD_BORDER

#define	HEIGHT			60
#define WIDTH			2

		for (iter.y = 0; iter.y < water->size.y; iter.y++)
			for (iter.x = 0; iter.x < WIDTH; iter.x++)
				water->set_water_depth(iter, HEIGHT);
		for (iter.y = 0; iter.y < water->size.y; iter.y++)
			for (iter.x = water->size.x - WIDTH - 2; iter.x < water->size.x - 2; iter.x++)
				water->set_water_depth(iter, HEIGHT);

		for (iter.x = 0; iter.x < water->size.x - 2; iter.x++)
			for (iter.y = 0; iter.y < WIDTH; iter.y++)
				water->set_water_depth(iter, HEIGHT);
		for (iter.x = 0; iter.x < water->size.x - 2; iter.x++)
			for (iter.y = water->size.y - WIDTH - 2; iter.y < water->size.y - 2; iter.y++)
				water->set_water_depth(iter, HEIGHT);
#endif

		water->update_height();
		water->update_color();
		water->upload_buffer(mod1_model_data::slot_point);
		water->upload_buffer(mod1_model_data::slot_color);

		return (true);
	}

	if (key != GLFW_KEY_ENTER)
		return (true);

	static int			kostyl = 0;

	if (kostyl++ % 2 == 1)
		return (false);

#ifdef FLOOD_POINT

#define A_X				0
#define A_Y				0

#define D_X				1
#define D_Y				1

	for (int y = 0; y < D_Y; y++)
		for (int x = 0; x < D_X; x++)
			water->water_depth[mod1_point2<int>(A_X + x, A_Y + y)] += 1;
#endif

#ifdef FLOOD_UNIFORM
	static float		level = 0;

	if (level > water->terrain->max_raw.z)
		return (false);
	for (iter.y = 0; iter.y < water->terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < water->terrain->size.x; iter.x++)
			if (water->get_pressure(iter) < level)
				water->add_water(iter, 1);
	level += water->water_drop_height;
#endif

#ifndef FLOOD_UNIFORM
	water->gravity();
#endif
	water->update_height();
	water->update_color();
	water->upload_buffer(mod1_model_data::slot_point);
	water->upload_buffer(mod1_model_data::slot_color);
	return (true);
}

void					mod1_water::update_color()
{
	mod1_point2<int>	iter;
	mod1_point3<float>	color;
	float 				pressure;
	float 				*ptr;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			pressure = get_total_height(iter);
			for (int i = 0; i < 3; i++)
				color[i] = mod1_terrain::interpolate_cosine(
					MOD1_WATER_COLOR_A[i],
					MOD1_WATER_COLOR_B[i],
					pressure / 60);
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_color);
			for (int i = 0; i < 3; i++)
				ptr[i] = color[i];
		}
}