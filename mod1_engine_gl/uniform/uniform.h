#pragma once

#include "mod1_engine_gl/namespace.h"

class				mod1_engine_gl::uniform
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_set, "Mod1 Engine GL, Uniform : Object is not connected to program")

	explicit		uniform(const char *name);
					~uniform() = default;

	void			connect(const unsigned int &program);

	void 			upload(const int &data);
	void 			upload(const float &data);
	void 			upload(const glm::vec3 &data);
	void 			upload(const glm::mat4 &data);

private :

	bool 			is_connected = false;

	unsigned int	id = -1;
	const char		*name = nullptr;
};
