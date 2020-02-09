#include "water.h"

using namespace			mod1_algorithm;

MOD1_GENERATE_EXCEPTION_DEFINITION(water, exception_logic)
MOD1_GENERATE_EXCEPTION_DEFINITION(water, exception_unknown_flow_type)
MOD1_GENERATE_EXCEPTION_DEFINITION(water, exception_color_redefinition)
MOD1_GENERATE_EXCEPTION_DEFINITION(water, exception_color_min)
MOD1_GENERATE_EXCEPTION_DEFINITION(water, exception_color_max)

						water::water(mod1_engine_cl::core &core, class terrain const *terrain) :
						terrain(terrain),
						cl_core(core)
{}