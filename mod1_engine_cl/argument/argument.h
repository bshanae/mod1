#pragma once

#include "mod1_main/mod1_generic.h"

#include "mod1_engine_cl/namespace.h"

enum class					mod1_engine_cl::argument_type
{
	read_only = CL_MEM_READ_ONLY,
	write_only = CL_MEM_WRITE_ONLY,
	read_write = CL_MEM_READ_WRITE
};

class						mod1_engine_cl::argument
{
	friend class 			kernel;

public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_build, "Mod1 Engine CL, Argument : Object is not built")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_link, "Mod1 Engine CL, Argument : Object is not linked to kernel")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_null, "Mod1 Engine CL, Argument : Host ptr is NULL")

							argument() = default;
							~argument() = default;

	void 					read();
	void 					write();

private :

	bool 					is_built = false;
	bool					is_linked = false;

	const cl::CommandQueue	*queue = nullptr;
	cl::Buffer				buffer;
	void					*host_ptr = nullptr;
	int 					host_size = -1;

							argument(
							const cl::Context *context,
							const cl::CommandQueue *queue,
							void *ptr,
							const int &size,
							const argument_type &type);
	void					link(cl::Kernel kernel, const int &index);
};


