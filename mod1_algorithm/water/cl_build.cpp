#include "water.h"

using namespace			mod1_algorithm;

void					water::cl_build()
{
	cl_build_debug();
	cl_build_flow_update();
	cl_build_flow_limit();
}

void					water::cl_build_debug()
{
	cl_kernel_debug = cl_core.generate_kernel();
	cl_kernel_debug.add_source("source_cl/global.cl");
	cl_kernel_debug.add_source("source_cl/data.cl");
	cl_kernel_debug.add_source("source_cl/kernel_debug.cl");
	cl_kernel_debug.build("debug", 1);
}

void					water::cl_build_flow_update()
{
	cl_kernel_flow_update = cl_core.generate_kernel();
	cl_kernel_flow_update.add_source("source_cl/global.cl");
	cl_kernel_flow_update.add_source("source_cl/data.cl");
	cl_kernel_flow_update.add_source("source_cl/kernel_update_flow.cl");
	cl_kernel_flow_update.build("update_flow", water_data.size());
}

void					water::cl_build_flow_limit()
{
	cl_kernel_flow_limit = cl_core.generate_kernel();
	cl_kernel_flow_limit.add_source("source_cl/global.cl");
	cl_kernel_flow_limit.add_source("source_cl/data.cl");
	cl_kernel_flow_limit.add_source("source_cl/kernel_limit_flow.cl");
	cl_kernel_flow_limit.build("limit_flow", water_data.size());
}
