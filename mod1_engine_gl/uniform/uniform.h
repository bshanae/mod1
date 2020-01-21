#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_generic.h"

#include "mod1_engine_gl/namespace.h"

class				mod1_engine_gl::uniform
{
public :

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_set, "Mod1 Engine GL, Uniform : Object is not set")

	explicit		uniform(const char *name);
					~uniform() = default;

	void			set(const GLuint &program);

	void 			upload(const int &data);
	void 			upload(const float &data);
	void 			upload(const glm::vec3 &data);
	void 			upload(const glm::mat4 &data);

//private :

	bool 			is_set = false;

	GLuint			id;
	const char		*name;
};
