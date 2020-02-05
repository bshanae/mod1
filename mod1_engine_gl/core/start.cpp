#include "core.h"

using namespace			mod1_engine_gl;

void 					core::start()
{
	while (not glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		launch_signal();
	}
}