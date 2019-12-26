#include "mod1_main.h"

#include "mod1_plane.h"

int						main(int argc, char **argv)
{
	mod1_main			main;

	global_error->test_critical(argc > 1, "Invalid number of program arguments");

	main.map->source_parse(argv[1]);
	main.map->source_print();

//	main.map->model_push_color(mod1_point3<float>(1, 0, 0));
//	main.map->model_push_color(mod1_point3<float>(0, 0, 1));
//
//	main.map->model_build();

	mod1_plane			plane;

	auto				min = mod1_point2<int>(-100, -100);
	auto				max = mod1_point2<int>(100, 100);
	int					delta = 5;

	plane.set(min, max, delta);
	plane.build();

	main.renderer->load_model(&plane);
	main.renderer->loop();

	return (0);
}