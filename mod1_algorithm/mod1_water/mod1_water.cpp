#include "mod1_water.h"

						mod1_water::mod1_water(const mod1_terrain &terrain) :
						terrain(terrain)
{
	size = terrain.model_size;
}