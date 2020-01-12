#include "water.h"

MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(water, exception_unknown_flow_type)

						water::water(const mod1_algorithm::terrain *terrain) :
						terrain(terrain)
{}