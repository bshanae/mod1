#include "plane.h"

using namespace		mod1_algorithm;

MOD1_GENERATE_EXCEPTION_DEFINITION(plane, exception_coordinate)
MOD1_GENERATE_EXCEPTION_DEFINITION(plane, exception_logic)
MOD1_GENERATE_EXCEPTION_DEFINITION(plane, exception_color)
MOD1_GENERATE_EXCEPTION_DEFINITION(plane, exception_index_convention)
MOD1_GENERATE_EXCEPTION_DEFINITION(plane, exception_cut_style)

MOD1_GENERATE_GET_DEFINITION(plane, size)
MOD1_GENERATE_GET_DEFINITION(plane, real_size)
MOD1_GENERATE_GET_DEFINITION(plane, min)
MOD1_GENERATE_GET_DEFINITION(plane, max)
MOD1_GENERATE_GET_DEFINITION(plane, delta)
MOD1_GENERATE_GET_DEFINITION(plane, final_min)
MOD1_GENERATE_GET_DEFINITION(plane, final_max)