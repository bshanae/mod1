#pragma once

#include "mod1_main/mod1_generic.h"

#include "mod1_engine_cl/namespace.h"

#include "mod1_engine_cl/kenrel/kernel.h"

#include <string>


class							mod1_engine_cl::core
{
public :
								core();
								~core() = default;

	kernel						generate_kernel();

private :

	cl::Platform				platform;
	cl::Device					device;
	cl::Context					context;

	void 						set_platform();
	void 						set_device();
	void 						set_context();

};



