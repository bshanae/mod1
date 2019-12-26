#include "mod1_main.h"

#include "mod1_water.h"

int						main(int argc, char **argv)
{
	mod1_main			main;

	global_error->test_critical(argc > 1, "Invalid number of program arguments");


	main.terrain->push_color(mod1_point3<float>(1, 0, 0));
	main.terrain->push_color(mod1_point3<float>(0, 0, 1));

	main.terrain->parse(argv[1]);
	main.terrain->build();
	main.terrain->info();

	main.water->build();

	main.renderer->load_model(main.terrain->model());
	main.renderer->load_model(main.water->model());
	main.renderer->loop();

	return (0);
}