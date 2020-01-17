#include "kernel.h"

using namespace				mod1_engine_cl;

MOD1_GENERATE_EXCEPTION_DEFINITION(kernel, exception_source)
MOD1_GENERATE_EXCEPTION_DEFINITION(kernel, exception_compilation)
MOD1_GENERATE_EXCEPTION_DEFINITION(kernel, exception_build)

//							PUBLIC

void 						kernel::run()
{
	if (not is_built)
		throw (exception_build());
	queue.enqueueNDRangeKernel(object, cl::NullRange, cl::NDRange(kernel_number), cl::NullRange);
	queue.finish();
}

argument 					kernel::generate_argument(void *ptr, const int &size, const argument_type &type)
{
	argument				argument;

	if (not is_built)
		throw (exception_build());
	argument = mod1_engine_cl::argument(context, &queue, ptr, size, type);
	argument.link(object, argument_count++);
	return (argument);
}

//							PRIVATE

							kernel::kernel(
							const cl::Device *device,
							const cl::Context *context,
							const std::string &file,
							const std::string &function,
							const int &kernel_number)
{
	std::string				source;

	this->device = device;
	this->context = context;
	this->kernel_number = kernel_number;

	source = read_source(file);
	compile_program(source);
	set_queue();
	set_kernel(function);

	is_built = true;
}

std::string 				kernel::read_source(const std::string &filename)
{
	std::ifstream			stream_f;
	std::stringstream		stream_s;

	stream_f.open(filename);
	if (!stream_f.is_open())
		throw (exception_source());
	stream_s << stream_f.rdbuf();
	return (stream_s.str());
}

void 						kernel::compile_program(const std::string &source)
{
	std::string				log;

	sources.emplace_back(source.c_str(), source.length());
	program = cl::Program(*context, sources);
	if(program.build({*device}) != CL_SUCCESS)
	{
		log = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(*device);

		printf("Log : %s\n", log.c_str());
		throw (exception_compilation());
	}
}

void 						kernel::set_queue()
{
	queue = cl::CommandQueue(*context, *device);
}

void 						kernel::set_kernel(const std::string &function)
{
	object = cl::Kernel(program, function.c_str());
}