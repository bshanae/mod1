#pragma once

#include "mod1_error.h"
#include "mod1_renderer.h"
#include "mod1_terrain.h"
#include "mod1_water.h"


class 				mod1_main
{

public :

					mod1_main();
					~mod1_main();

	mod1_renderer	*renderer = nullptr;
	mod1_terrain	*terrain = nullptr;
	mod1_water		*water = nullptr;

private :

	mod1_error		error;
};