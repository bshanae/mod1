#include "core.h"

using namespace					mod1_engine_cl;

//								PUBLIC

								core::core()
{
	set_platform();
	set_device();
	set_context();
}

kernel							core::generate_kernel()
{
	return (kernel(&device, &context));
}

//								PRIVATE

void 							core::set_platform()
{
	std::vector<cl::Platform>	platform_array;

	cl::Platform::get(&platform_array);
	platform = platform_array[0];
}

void 							core::set_device()
{
	std::vector<cl::Device>		device_array;

	platform.getDevices(CL_DEVICE_TYPE_GPU, &device_array);
	device = device_array[0];
}

void 					core::set_context()
{
	context = cl::Context(device);
}
