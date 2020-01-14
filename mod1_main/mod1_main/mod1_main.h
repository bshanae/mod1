#pragma once

#include "mod1_engine/mod1_engine.h"
#include "mod1_algorithm/mod1_terrain/mod1_terrain.h"
#include "mod1_algorithm/mod1_water/mod1_water.h"

class 						mod1_main
{

public :

							mod1_main(int argc, char **argv);
							~mod1_main();

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_invalid_arguments, "Mod1 Main : Invalid number of arguments")

	void					build();
	void					loop();

	mod1_engine::renderer	*renderer = nullptr;
	mod1_terrain			*terrain = nullptr;
	mod1_water				*water = nullptr;

private :

	char					*source;

};