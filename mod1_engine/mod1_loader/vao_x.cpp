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

void 					mod1_loader::vao_edit_attribute(GLuint vao, int attribute, int element_size, GLenum type, const void *data, int data_size)
{
	GLuint				vbo;

	vbo = vbo_build();
	vao_bind(vao);
	vbo_buffer(vbo, data, data_size);
	vbo_bind(vbo);
	glVertexAttribPointer(attribute, element_size, type, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(attribute);
	vbo_unbind();
	vao_unbind();
}