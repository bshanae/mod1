#include "water.h"

using namespace			mod1_algorithm;

void					water::cl_build()
{
	cl_kernel_debug = cl_core.generate_kernel("source_cl/kernel.cl", "debug", 1);
	cl_kernel_flow_update = cl_core.generate_kernel("source_cl/kernel.cl", "update_flow", 1);
}