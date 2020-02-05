#include "core.h"

using namespace		mod1_engine_gl;

void				core::clear(const point3<float> &color)
{
	glClearColor(color.x, color.y, color.z, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}