#include "control.h"

using namespace					mod1_engine_cl;

//								PUBLIC

MOD1_GENERATE_EXCEPTION_DEFINITION(control, exception_source)
MOD1_GENERATE_EXCEPTION_DEFINITION(control, exception_compilation)
MOD1_GENERATE_EXCEPTION_DEFINITION(control, exception_build)

								control::control()
{
	set_platform();
	set_device();
	set_context();
}

void							control::build(const char *filename)
{
	std::string					string(filename);

	build(string);
}

void							control::build(const std::string &filename)
{
	std::string					source;

	source = read_source(filename);
	compile_program(source);
	set_queue();
	set_kernel();

	int							A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int							B[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int							C[10];

	auto 						arg_a = create_argument(A, sizeof(int) * 10, argument_type::read_only);
	auto 						arg_b = create_argument(B, sizeof(int) * 10, argument_type::read_only);
	auto 						arg_c = create_argument(C, sizeof(int) * 10, argument_type::write_only);

	link_argument(arg_a);
	link_argument(arg_b);
	link_argument(arg_c);

	arg_a.write();
	arg_b.write();

	queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(10), cl::NullRange);
	queue.finish();

	arg_c.read();

	printf("C : ");
	for (auto &i : C)
		printf("%d ", i);
	printf("\n");

	is_built = true;
}

argument 						control::create_argument(void *ptr, const int &size, const argument_type &type)
{
	if (not is_built)
		throw (exception_build());
	return (argument(context, &queue, ptr, size, type));
}

void							control::link_argument(argument &argument)
{
	if (not is_built)
		throw (exception_build());
	argument.link(kernel, argument_count++);
}


//								PRIVATE

void 							control::set_platform()
{
	std::vector<cl::Platform>	platform_array;

	cl::Platform::get(&platform_array);
	platform = platform_array[0];
}

void 							control::set_device()
{
	std::vector<cl::Device>		device_array;

	platform.getDevices(CL_DEVICE_TYPE_GPU, &device_array);
	device = device_array[0];
}

void 					control::set_context()
{
	context = cl::Context(device);
}

std::string 				control::read_source(const std::string &filename)
{
	std::ifstream			stream_f;
	std::stringstream		stream_s;

	stream_f.open(filename);
	if (!stream_f.is_open())
		throw (exception_source());
	stream_s << stream_f.rdbuf();
	return (stream_s.str());
}

void 						control::compile_program(const std::string &source)
{
	std::string				log;

	sources.emplace_back(source.c_str(), source.length());
	program = cl::Program(context, sources);
	if(program.build({device}) != CL_SUCCESS)
	{
		log = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(device);

		printf("Log : %s\n", log.c_str());
		throw (exception_compilation());
	}
}

void 						control::set_queue()
{
	queue = cl::CommandQueue(context, device);
}

void 						control::set_kernel()
{
	kernel = cl::Kernel(program, "test");
}