#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_macros.h"
#include "mod1_main/mod1_generic.h"
#include "mod1_main/mod1_control.h"

#include "mod1_engine/namespace.h"

#include "mod1_engine/shader/shader.h"

class					mod1_engine::program
{

public :

						program();
						~program();

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_compilation, "Mod1 Program : Compilation error")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_link, "Mod1 Program : Object is nit linked")

	void				start();
	void				stop();

	void 				add_shader(const shader_type &type, const char *source);
	void				link();

	GLuint				object();

private :

	bool				is_linked = false;
	GLuint 				object_internal;

	void				check_error();
};
