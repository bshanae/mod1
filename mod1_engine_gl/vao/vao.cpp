#include "vao.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(vao, exception_template)

					vao::vao()
{
	glGenVertexArrays(1, &object);
}

					vao::~vao()
{
	glDeleteVertexArrays(1, &object);
}

void				vao::bind() const
{
	glBindVertexArray(object);
}

void				vao::unbind()
{
	glBindVertexArray(0);
}
