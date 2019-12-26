#include "mod1_main.h"

mod1_error			*global_error;


					mod1_main::mod1_main()
{
	global_error = &error;
	terrain = new mod1_terrain;
	renderer = new mod1_renderer;
}

					mod1_main::~mod1_main()
{
	delete terrain;
	delete renderer;
}
