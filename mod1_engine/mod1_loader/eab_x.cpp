#include "mod1_loader.h"

GLuint					mod1_loader::eab_build()
{
	GLuint				result;

	glGenBuffers(1, &result);
	eab_vector.push_back(result);
	return (result);
}

void					mod1_loader::eab_bind(GLuint eab)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eab);
}

void					mod1_loader::eab_unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void 					mod1_loader::eab_buffer(GLuint eab, const void *data, int data_size)
{
	eab_bind(eab);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data_size, data, GL_STATIC_DRAW);
	eab_unbind();
}