#include "mod1_main.h"

#include <iostream>

void						main_unsafe(int argc, char **argv)
{
	mod1_main				main(argc, argv);

	main.terrain->push_color(mod1_point3<float>(1, 0, 0));
	main.terrain->push_color(mod1_point3<float>(1, 1, 1));

	main.build();

	main.terrain->info();

	main.loop();
}

int							main(int argc, char **argv)
{
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