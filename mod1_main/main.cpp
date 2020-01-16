#include "mod1_main/mod1_main/mod1_main.h"

#include <iostream>

#include "mod1_engine_cl/mod1_engine_cl.h"

void						main_unsafe(int argc, char **argv)
{
	mod1_main				main(argc, argv);

	mod1_engine_cl::control	control;

	control.build("source_cl/kernel.cl");

	main.terrain->add_color(mod1_engine_gl::point3<int>(101, 67, 33));
	main.terrain->add_color(mod1_engine_gl::point3<int>(80, 171, 93));
	main.terrain->add_color(mod1_engine_gl::point3<int>(120, 120, 120));

	main.build();

	main.terrain->info();

	main.loop();
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