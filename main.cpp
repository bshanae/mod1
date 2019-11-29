#include "mod1_error.h"
#include "mod1_map.h"

int						main(int argc, char **argv)
{
	mod1_error			error;
	mod1_map			map(error);

	error.test_critical(argc > 1, "Invalid number of program arguments");

	map.parse(argv[1]);
	map.print();

	return 0;
}