#include "mod1_error.h"
#include "mod1_map.h"
#include "mod1_drawer.h"

int						main(int argc, char **argv)
{
	mod1_error			error;
	mod1_map			map(error);
	mod1_drawer			drawer(error);

	error.test_critical(argc > 1, "Invalid number of program arguments");

	map.parse(argv[1]);
	map.print();

	drawer.loop();

	return 0;
}