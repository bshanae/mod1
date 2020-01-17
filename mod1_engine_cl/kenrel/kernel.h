#pragma once

#include "mod1_main/mod1_generic.h"

#include "mod1_engine_cl/namespace.h"

#include "mod1_engine_cl/argument/argument.h"

#include <fstream>
#include <sstream>

class						mod1_engine_cl::kernel
{
	friend class 			core;

public :

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_source, "Mod1 Kernel : Invalid source file")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_compilation, "Mod1 Kernel : Compilation error")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_build, "Mod1 Kernel : Object is not built")

							kernel() = default;
							~kernel() = default;

	void					run();

	argument 				generate_argument(
							void *ptr,
							const int &size,
							const argument_type &type,
							const bool &link = true);
	void 					link_argument(argument &argument);

private :

	bool 					is_built = false;
	int						kernel_number = 0;
	int 					argument_count = 0;

	const cl::Device		*device = nullptr;
	const cl::Context		*context = nullptr;
	cl::Program::Sources	sources;
	cl::Program				program;
	cl::CommandQueue		queue;
	cl::Kernel				object;

							kernel(
							const cl::Device *device,
							const cl::Context *context,
							const std::string &file,
							const std::string &function,
							const int &kernel_number);

	static std::string		read_source(const std::string &file);
	void 					compile_program(const std::string &source);
	void 					set_queue();
	void 					set_kernel(const std::string &function);
};


