#include "core.h"

using namespace		mod1_engine_gl;

void 				core::use_depth_test(const bool &state)
{
	if (state)
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);
}