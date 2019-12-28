#include "mod1_loader.h"

GLuint					mod1_loader::vao_build()
{
	GLuint				result;

	glGenVertexArrays(1, &result);
	vbo_vector.push_back(result);
	return (result);
}

void					mod1_loader::vao_bind(GLuint vao)
{
	glBindVertexArray(vao);
}

void					mod1_loader::vao_unbind()
{
	glBindVertexArray(0);
}