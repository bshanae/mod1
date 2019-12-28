#include "mod1_main.h"

					mod1_main::mod1_main(int argc, char **argv)
{
	renderer = new mod1_renderer;
	terrain = new mod1_terrain;
	water = new mod1_water(terrain);
	if (argc < 2)
		throw (exception_invalid_arguments());
	source = argv[1];
}

					mod1_main::~mod1_main()
{
	delete renderer;
	delete terrain;
	delete water;
}

void				mod1_main::build()
{
	terrain->parse(source);
	terrain->build();
	water->build();
}

void				mod1_main::loop()
{
	renderer->add_callback(mod1_water::callback, water);

	renderer->load_model(terrain->model());
	renderer->load_model(water->model());
	renderer->loop();
}