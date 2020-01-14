#include "water.h"

using namespace			mod1_algorithm;

MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(water, exception_unknown_flow_type)

						water::water(mod1_algorithm::terrain const *terrain) :
						terrain(terrain)
{}