#include "general.h"

MOD1_GENERATE_EXCEPTION_DEFINITION(general, exception_arguments)

					general::general(int argc, char **argv)
{
	renderer = new ::renderer;
	terrain = new mod1_algorithm::terrain;
	water = new mod1_algorithm::water(terrain);
	if (argc < 2)
		throw (exception_arguments());
	source = argv[1];
}

					general::~general()
{
	delete renderer;
	delete terrain;
	delete water;
}

void				general::build()
{
	terrain->parse(source);
	terrain->build();
	water->build();
}

void				general::loop()
{
	renderer->add_callback(mod1_algorithm::water::callback, water);

#if MOD1_ENABLED(MOD1_USE_TERRAIN)
	renderer->add_model(terrain->model());
#endif

#if MOD1_ENABLED(MOD1_USE_WATER)
	renderer->add_model(water->model());
#endif

	renderer->loop();
}