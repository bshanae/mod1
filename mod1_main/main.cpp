#include "mod1_main.h"

int						main(int argc, char **argv)
{
	mod1_main			main;

	global_error->test_critical(argc > 1, "Invalid number of program arguments");

	main.map->source_parse(argv[1]);
	main.map->source_print();

	main.map->model_push_color(mod1_point3<float>(1, 0, 0));
	main.map->model_push_color(mod1_point3<float>(0, 0, 1));

	main.map->model_build();

	main.renderer->load_model(main.map);
	main.renderer->loop();

	return (0);
}