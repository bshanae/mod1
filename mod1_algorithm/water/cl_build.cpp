#include "water.h"

using namespace			mod1_algorithm;

void					water::cl_build()
{
	cl_build_debug();
	cl_build_update_flow();
	cl_build_limit_flow();
	cl_build_update_depth();
}

void					water::cl_build_debug()
{
	cl_kernel_debug = cl_core.generate_kernel();
	cl_kernel_debug.add_source("source_cl/global.cl");
	cl_kernel_debug.add_source("source_cl/data.cl");
	cl_kernel_debug.add_source("source_cl/data_macro_wrap.cl");
	cl_kernel_debug.add_source("source_cl/kernel_debug.cl");
	cl_kernel_debug.build("debug", 1);
}

void					water::cl_build_update_flow()
{
	cl_kernel_update_flow = cl_core.generate_kernel();
	cl_kernel_update_flow.add_source("source_cl/global.cl");
	cl_kernel_update_flow.add_source("source_cl/data.cl");
	cl_kernel_update_flow.add_source("source_cl/data_macro_wrap.cl");
	cl_kernel_update_flow.add_source("source_cl/kernel_update_flow.cl");
	cl_kernel_update_flow.build("update_flow", water_data.size());
}

void					water::cl_build_limit_flow()
{
	cl_kernel_limit_flow = cl_core.generate_kernel();
	cl_kernel_limit_flow.add_source("source_cl/global.cl");
	cl_kernel_limit_flow.add_source("source_cl/data.cl");
	cl_kernel_limit_flow.add_source("source_cl/data_macro_wrap.cl");
	cl_kernel_limit_flow.add_source("source_cl/kernel_limit_flow.cl");
	cl_kernel_limit_flow.build("limit_flow", water_data.size());
}

void					water::cl_build_update_depth()
{
	cl_kernel_update_depth = cl_core.generate_kernel();
	cl_kernel_update_depth.add_source("source_cl/global.cl");
	cl_kernel_update_depth.add_source("source_cl/data.cl");
	cl_kernel_update_depth.add_source("source_cl/data_macro_wrap.cl");
	cl_kernel_update_depth.add_source("source_cl/kernel_update_depth.cl");
	cl_kernel_update_depth.build("update_depth", water_data.size());
}
