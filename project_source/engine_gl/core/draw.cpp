#include "core.h"

using namespace		mod1_engine_gl;

void				core::draw(const int &count)
{
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}