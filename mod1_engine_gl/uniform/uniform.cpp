#include "uniform.h"

using namespace	mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(uniform, exception_set)

				uniform::uniform(const char *name) :
				id(),
				name(name)
{}

void			uniform::connect(const unsigned int &program)
{
	id = glGetUniformLocation(program, name);
	is_connected = true;
}

void 			uniform::upload(const int &data)
{
	if (not is_connected)
		throw (exception_set());
	glUniform1i(id, 0);
}

void 			uniform::upload(const float &data)
{
	if (not is_connected)
		throw (exception_set());
	glUniform1f(id, data);
}

void 			uniform::upload(const glm::vec3 &data)
{
	if (not is_connected)
		throw (exception_set());
	glUniform3f(id, data.x, data.y, data.z);
}

void 			uniform::upload(const glm::mat4 &data)
{
	if (not is_connected)
		throw (exception_set());
	glUniformMatrix4fv(id, 1, GL_FALSE, glm::value_ptr(data));
}
