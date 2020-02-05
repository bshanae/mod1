#include "core.h"

using namespace		mod1_engine_gl;

void 				core::show_polygon_back(const bool &state)
{
	if (state)
		glDisable(GL_CULL_FACE);
	else
	{
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	}
}