#include "mod1_general/general/general.h"

#include <iostream>

using namespace				mod1_algorithm;

void						main_unsafe(int argc, char **argv)
{
	general					general(argc, argv);

	general.terrain()->add_color(plane_color::negative, mod1_engine_gl::point3<int>(77, 51, 25));
	general.terrain()->add_color(plane_color::negative, mod1_engine_gl::point3<int>(101, 67, 33));
	general.terrain()->add_color(plane_color::negative, mod1_engine_gl::point3<int>(201, 178, 99));

	general.terrain()->add_color(plane_color::positive, mod1_engine_gl::point3<int>(201, 178, 99));
	general.terrain()->add_color(plane_color::positive, mod1_engine_gl::point3<int>(80, 171, 93));
	general.terrain()->add_color(plane_color::positive, mod1_engine_gl::point3<int>(120, 120, 120));

	general.build();
	general.start();
}

int							main(int argc, char **argv)
{
	main_unsafe(argc, argv);
	return (0);
	try
	{
		main_unsafe(argc, argv);
		return (0);
	}
	catch (std::exception &exception)
	{
		printf("\n\033[0;31m");
		printf("Mod1 : Exiting with uncaught exception\n");
		printf("%s\n", exception.what());
		printf("\033[0m\n");
		return (1);
	}
}