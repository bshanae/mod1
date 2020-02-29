#include "core.h"

using namespace					mod1_engine_cl;

//								PUBLIC

								core::core()
{
MOD1_GENERATE_MESSAGE("")

	set_platform();
	set_device();
	set_context();

MOD1_GENERATE_MESSAGE("Mod1 Engine CL, Core : Ready")
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

MOD1_GENERATE_MESSAGE("Mod1 Engine CL, Core : Platform is set")
}

void 							core::set_device()
{
	std::vector<cl::Device>		device_array;

	platform.getDevices(CL_DEVICE_TYPE_GPU, &device_array);
	device = device_array[0];

MOD1_GENERATE_MESSAGE("Mod1 Engine CL, Core : Device is set")
}

void 					core::set_context()
{
	context = cl::Context(device);

MOD1_GENERATE_MESSAGE("Mod1 Engine CL, Core : Context is set")
}
