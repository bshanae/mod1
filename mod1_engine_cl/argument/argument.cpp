#include "argument.h"

using namespace		mod1_engine_cl;

MOD1_GENERATE_EXCEPTION_DEFINITION(argument, exception_build)
MOD1_GENERATE_EXCEPTION_DEFINITION(argument, exception_link)
MOD1_GENERATE_EXCEPTION_DEFINITION(argument, exception_null)


					argument::argument(
					const cl::Context &context,
					const cl::CommandQueue *queue,
					void *ptr,
					const int &size,
					const argument_type &type) :
					queue(queue)
{
	host_ptr = ptr;
	host_size = size;
	buffer = cl::Buffer(context, (int)type, size);
	is_built = true;
}

void				argument::link(cl::Kernel kernel, const int &index)
{
	if (not is_built)
		throw (exception_build());
	kernel.setArg(index, buffer);
	is_linked = true;
}

void 				argument::read()
{
	if (not is_linked)
		throw (exception_link());
	if (not host_ptr)
		throw(exception_null());
	queue->enqueueReadBuffer(buffer, CL_TRUE, 0, host_size, host_ptr);
}

void 				argument::write()
{
	if (not is_linked)
		throw (exception_link());
	if (not host_ptr)
		throw(exception_null());
	queue->enqueueWriteBuffer(buffer, CL_TRUE, 0, host_size, host_ptr);
}