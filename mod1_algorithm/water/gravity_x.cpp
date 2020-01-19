#include "water.h"

using namespace			mod1_algorithm;

void					water::gravity()
{
	cl_kernel_update_flow.run();
	cl_kernel_limit_flow.run();
	cl_kernel_update_depth.run();

//	cl_kernel_debug.run();

	cl_arg_water_data.read();

	update_model();
	update_color();

	update_normal();
}