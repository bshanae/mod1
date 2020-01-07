#pragma once

#include "mod1_renderer.h"
#include "mod1_terrain.h"
#include "mod1_water.h"

class 				mod1_main
{

public :

					mod1_main(int argc, char **argv);
					~mod1_main();

	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_invalid_arguments, "Mod1 Main : Invalid number of arguments")

	void			build();
	void			loop();

	mod1_renderer	*renderer = nullptr;
	mod1_terrain	*terrain = nullptr;
	mod1_water		*water = nullptr;

private :

	char			*source;

};