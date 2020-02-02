#include "vbo.h"

using namespace		mod1_engine_gl;

					vbo::vbo()
{
	glGenBuffers(1, &object);
}

					vbo::~vbo()
{
	glDeleteBuffers(1, &object);
}

void				vbo::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, object);
}

void				vbo::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
