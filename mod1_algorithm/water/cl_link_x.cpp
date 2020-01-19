#include "water.h"

using namespace			mod1_algorithm;

void					water::cl_link()
{
	cl_link_debug();
	cl_link_flow_update();
	cl_link_flow_limit();
}

void					water::cl_link_debug()
{
	cl_kernel_debug.link_argument(cl_arg_const_flow);
	cl_kernel_debug.link_argument(cl_arg_const_depth);
	cl_kernel_debug.link_argument(cl_arg_size);
	cl_kernel_debug.link_argument(cl_arg_terrain_data);
	cl_kernel_debug.link_argument(cl_arg_water_data);
	cl_kernel_debug.link_argument(cl_arg_flow_horizontal);
	cl_kernel_debug.link_argument(cl_arg_flow_vertical);
}

void					water::cl_link_flow_update()
{
	cl_kernel_flow_update.link_argument(cl_arg_const_flow);
	cl_kernel_flow_update.link_argument(cl_arg_const_depth);
	cl_kernel_flow_update.link_argument(cl_arg_size);
	cl_kernel_flow_update.link_argument(cl_arg_terrain_data);
	cl_kernel_flow_update.link_argument(cl_arg_water_data);
	cl_kernel_flow_update.link_argument(cl_arg_flow_horizontal);
	cl_kernel_flow_update.link_argument(cl_arg_flow_vertical);
}

void					water::cl_link_flow_limit()
{
	cl_kernel_flow_limit.link_argument(cl_arg_const_flow);
	cl_kernel_flow_limit.link_argument(cl_arg_const_depth);
	cl_kernel_flow_limit.link_argument(cl_arg_size);
	cl_kernel_flow_limit.link_argument(cl_arg_terrain_data);
	cl_kernel_flow_limit.link_argument(cl_arg_water_data);
	cl_kernel_flow_limit.link_argument(cl_arg_flow_horizontal);
	cl_kernel_flow_limit.link_argument(cl_arg_flow_vertical);
}