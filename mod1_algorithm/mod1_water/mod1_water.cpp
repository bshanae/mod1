#include "mod1_water.h"

						mod1_water::mod1_water(mod1_terrain const *terrain) :
						terrain(terrain)

{
	random_generator = std::mt19937(random_device());

	direction_vector.emplace_back(-1, -1);
	direction_vector.emplace_back(-1, 0);
	direction_vector.emplace_back(-1, +1);
	direction_vector.emplace_back(0, -1);
	direction_vector.emplace_back(0, 0);
	direction_vector.emplace_back(0, +1);
	direction_vector.emplace_back(+1, -1);
	direction_vector.emplace_back(+1, 0);
	direction_vector.emplace_back(+1, +1);
}

bool 					mod1_water::callback(int key, void *ptr)
{
	auto				water = (mod1_water *)ptr;
	mod1_point2<int>	iter;

	if (key != GLFW_KEY_ENTER)
		return (false);
//	for (iter.y = 0; iter.y < water->terrain->size.y; iter.y++)
//		for (iter.x = 0; iter.x < water->terrain->size.x; iter.x++)
//			if (!water->get_height(iter))
//				water->add_water(iter);
	water->gravity();
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
	int 				water;
	float 				*ptr;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			water = get_water(iter);
			for (int i = 0; i < 3; i++)
				color[i] = mod1_terrain::interpolate_cosine(
					MOD1_WATER_COLOR_A[i],
					MOD1_WATER_COLOR_B[i],
					(float)water / 20.f);
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_color);
			for (int i = 0; i < 3; i++)
				ptr[i] = color[i];
		}
}