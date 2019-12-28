#include "mod1_water.h"

						mod1_water::mod1_water(mod1_terrain const *terrain) :
						terrain(terrain)
{}

void 					mod1_water::callback(int key, void *ptr)
{
	auto				water = (mod1_water *)ptr;

	if (key == GLFW_KEY_1)
		printf("hi %f\n", water->water_drop_height);
}

