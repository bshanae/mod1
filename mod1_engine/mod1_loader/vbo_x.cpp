#include "mod1_loader.h"

GLuint					mod1_loader::vbo_build()
{
	GLuint				result;

	glGenBuffers(1, &result);
	vao_vector.push_back(result);
	return (result);
}

void					mod1_loader::vbo_bind(GLuint vbo)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}
void					mod1_loader::vbo_unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void 					mod1_loader::vbo_buffer(GLuint vbo, const void *data, int data_size)
{
	vbo_bind(vbo);
	glBufferData(GL_ARRAY_BUFFER, data_size, data, GL_STATIC_DRAW);
	vbo_unbind();
}