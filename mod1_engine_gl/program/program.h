#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/shader/shader.h"
#include "mod1_engine_gl/uniform/uniform.h"

class					mod1_engine_gl::program
{

public :

						program();
						~program();

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_compilation, "Mod1 Engine GL, Program : Compilation error")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_link, "Mod1 Engine GL, Program : Object is nit linked")

	void				start();
	void				stop();

	void 				add_shader(const shader_type &type, const char *source);
	void				link();
	void 				set_uniform(uniform &uniform);

	GLuint				object();

private :

	bool				is_linked = false;
	GLuint 				object_internal;

	void				check_error();
};
