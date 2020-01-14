#include "mod1_water.h"

MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(mod1_water, exception_unknown_flow_type)

						mod1_water::mod1_water(mod1_terrain const *terrain) :
						terrain(terrain)
{

}