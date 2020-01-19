#include "water.h"

using namespace			mod1_algorithm;

void					water::cl_link()
{
	cl_link_debug();
	cl_link_update_flow();
	cl_link_limit_flow();
	cl_link_update_depth();
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

void					water::cl_link_update_flow()
{
	cl_kernel_update_flow.link_argument(cl_arg_const_flow);
	cl_kernel_update_flow.link_argument(cl_arg_const_depth);
	cl_kernel_update_flow.link_argument(cl_arg_size);
	cl_kernel_update_flow.link_argument(cl_arg_terrain_data);
	cl_kernel_update_flow.link_argument(cl_arg_water_data);
	cl_kernel_update_flow.link_argument(cl_arg_flow_horizontal);
	cl_kernel_update_flow.link_argument(cl_arg_flow_vertical);
}

void					water::cl_link_limit_flow()
{
	cl_kernel_limit_flow.link_argument(cl_arg_const_flow);
	cl_kernel_limit_flow.link_argument(cl_arg_const_depth);
	cl_kernel_limit_flow.link_argument(cl_arg_size);
	cl_kernel_limit_flow.link_argument(cl_arg_terrain_data);
	cl_kernel_limit_flow.link_argument(cl_arg_water_data);
	cl_kernel_limit_flow.link_argument(cl_arg_flow_horizontal);
	cl_kernel_limit_flow.link_argument(cl_arg_flow_vertical);
}

void					water::cl_link_update_depth()
{
	cl_kernel_update_depth.link_argument(cl_arg_const_flow);
	cl_kernel_update_depth.link_argument(cl_arg_const_depth);
	cl_kernel_update_depth.link_argument(cl_arg_size);
	cl_kernel_update_depth.link_argument(cl_arg_terrain_data);
	cl_kernel_update_depth.link_argument(cl_arg_water_data);
	cl_kernel_update_depth.link_argument(cl_arg_flow_horizontal);
	cl_kernel_update_depth.link_argument(cl_arg_flow_vertical);
}