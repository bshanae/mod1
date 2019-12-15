#include "mod1_main.h"
#include "mod1_terrain.h"

int						main(int argc, char **argv)
{
	mod1_main			main;

	global_error->test_critical(argc > 1, "Invalid number of program arguments");

	main.map->parse(argv[1]);
	main.map->print();

	mod1_terrain		terrain(0, 10);

	main.renderer->load_model(&terrain);
	main.renderer->loop();

	return 0;
}