#include "mod1_main.h"

int						main(int argc, char **argv)
{
	mod1_main			main;

	global_error->test_critical(argc > 1, "Invalid number of program arguments");

	main.map->source_parse(argv[1]);
	main.map->source_print();

	main.map->model_build();

	return 0;
}