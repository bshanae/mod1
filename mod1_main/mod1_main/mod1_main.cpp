#include "mod1_main.h"

mod1_error			*global_error;


					mod1_main::mod1_main()
{
	global_error = &error;
	renderer = new mod1_renderer;
	terrain = new mod1_terrain;
	water = new mod1_water(terrain);
}

					mod1_main::~mod1_main()
{
	delete renderer;
	delete terrain;
	delete water;
}
