#pragma once

#include "mod1_main/mod1_generic.h"

#include "mod1_engine_cl/namespace.h"

#include "mod1_libraries/OpenCL/cl.hpp"

#include <string>
#include <fstream>
#include <sstream>

class							mod1_engine_cl::control
{
public :

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_source, "Mod1 Cl_control : Invalid source file")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_compilation, "Mod1 Cl_control : Compilation error")

								control();
								~control();

	void						build(const char *filename);
	void						build(const std::string &filename);

private :

	cl::Platform				platform;
	cl::Device					device;
	cl::Context					context;
	cl::Program::Sources		sources;
	cl::Program					program;
	cl::CommandQueue			queue;
	cl::Kernel					kernel;

	void 						set_platform();
	void 						set_device();
	void 						set_context();
	std::string					read_source(const std::string &filename);
	void 						compile_program(const std::string &source);
	void 						set_queue();
	void 						set_kernel();
};



