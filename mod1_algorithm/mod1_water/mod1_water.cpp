#include "mod1_water.h"

						mod1_water::mod1_water(mod1_terrain const *terrain) :
						terrain(terrain)
{}

bool 					mod1_water::callback(int key, void *ptr)
{
	auto				water = (mod1_water *)ptr;

	if (key == GLFW_KEY_1)
	{
		water->add_water(mod1_point2<int>(2, 2));
		water->gravity();
	}
	else
		return (false);
	water->update_height();
	water->upload_buffer(mod1_model_data::slot_point);
	return (true);
}

