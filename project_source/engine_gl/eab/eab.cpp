#include "eab.h"

using namespace		mod1_engine_gl;

					eab::eab()
{
	glGenBuffers(1, &object);
}
					eab::~eab()
{
	glDeleteBuffers(1, &object);
}

void				eab::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object);
}

void				eab::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
