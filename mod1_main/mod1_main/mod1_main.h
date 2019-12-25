#pragma once

#include "mod1_error.h"
#include "mod1_terrain.h"
#include "mod1_renderer.h"

class 				mod1_main
{

public :

					mod1_main();
					~mod1_main();

	mod1_terrain		*map;
	mod1_renderer	*renderer;

private :

	mod1_error		error;
};