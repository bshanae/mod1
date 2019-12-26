#include "mod1_water.h"

void 					mod1_water::build()
{
	set(terrain->min, terrain->max, terrain->delta);
	mod1_plane::build();
}