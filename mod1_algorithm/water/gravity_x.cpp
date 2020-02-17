#include "water.h"

using namespace			mod1_algorithm;

void					water::gravity()
{
	cl_kernel_update_flow.run();
	cl_kernel_limit_flow.run();

	cl_kernel_update_depth.run();

	cl_arg_water_data.read();

	update_model(true);
}