#include "loader.h"

using namespace			mod1_engine_gl;

unsigned int					loader::eab_build()
{
	unsigned int				result;

	glGenBuffers(1, &result);
	eab_vector.push_back(result);
	return (result);
}

void					loader::eab_bind(unsigned int eab)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eab);
}

void					loader::eab_unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
