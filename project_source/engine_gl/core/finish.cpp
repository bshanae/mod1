#include "core.h"

using namespace		mod1_engine_gl;

void				core::finish()
{
	glfwSetWindowShouldClose(window, GL_TRUE);
}