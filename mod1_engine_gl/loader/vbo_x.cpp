#include "loader.h"

using namespace			mod1_engine_gl;

GLuint					loader::vbo_build()
{
	GLuint				result;

	glGenBuffers(1, &result);
	vao_vector.push_back(result);
	return (result);
}

void					loader::vbo_bind(GLuint vbo)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}
void					loader::vbo_unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}