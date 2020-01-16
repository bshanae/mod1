#include "loader.h"

using namespace			mod1_engine_gl;

GLuint					loader::vao_build()
{
	GLuint				result;

	glGenVertexArrays(1, &result);
	vbo_vector.push_back(result);
	return (result);
}

void					loader::vao_bind(GLuint vao)
{
	glBindVertexArray(vao);
}

void					loader::vao_unbind()
{
	glBindVertexArray(0);
}