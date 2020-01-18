#include "water.h"

using namespace			mod1_algorithm;

void					water::cl_write()
{
	cl_arg_const_flow.write();
	cl_arg_const_depth.write();
	cl_arg_size.write();
	cl_arg_terrain_data.write();
	cl_arg_water_data.write();
	cl_arg_flow_horizontal.write();
	cl_arg_flow_vertical.write();
}