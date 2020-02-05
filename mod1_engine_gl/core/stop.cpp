#include "core.h"

using namespace		mod1_engine_gl;

void				core::stop()
{
	glfwSetWindowShouldClose(window, GL_TRUE);
}