#include "loader.h"

using namespace			mod1_engine;

GLuint					loader::eab_build()
{
	GLuint				result;

	glGenBuffers(1, &result);
	eab_vector.push_back(result);
	return (result);
}

void					loader::eab_bind(GLuint eab)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eab);
}

void					loader::eab_unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
