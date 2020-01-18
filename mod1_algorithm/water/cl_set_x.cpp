#include "water.h"

using namespace			mod1_algorithm;

void					water::cl_set()
{
	cl_set_const();
	cl_set_size();
	cl_set_terrain();
	cl_set_water();
	cl_set_flow();
}

void					water::cl_set_const()
{
	cl_arg_const_flow = cl_kernel_flow_update.generate_argument(
		&constant_flow, sizeof(float),
		mod1_engine_cl::argument_type::read_only, false);
	cl_arg_const_depth = cl_kernel_flow_update.generate_argument(
		&constant_depth, sizeof(float),
		mod1_engine_cl::argument_type::read_only, false);
}

void					water::cl_set_size()
{
	cl_arg_size = cl_kernel_flow_update.generate_argument(
		data_size.data(), data_size.size_in_bytes(),
		mod1_engine_cl::argument_type::read_only, false);
}

void					water::cl_set_terrain()
{
	cl_arg_terrain_data = cl_kernel_flow_update.generate_argument(
		terrain_data.data(), terrain_data.size_in_bytes(),
		mod1_engine_cl::argument_type::read_only, false);
}

void					water::cl_set_water()
{
	cl_arg_water_data = cl_kernel_flow_update.generate_argument(
		water_data.data(), water_data.size_in_bytes(),
		mod1_engine_cl::argument_type::read_write, false);
}

void					water::cl_set_flow()
{
	cl_arg_flow_horizontal = cl_kernel_flow_update.generate_argument(
		empty_data.data(), empty_data.size_in_bytes(),
		mod1_engine_cl::argument_type::read_write, false);
	cl_arg_flow_vertical = cl_kernel_flow_update.generate_argument(
		empty_data.data(), empty_data.size_in_bytes(),
		mod1_engine_cl::argument_type::read_write, false);
}