#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_macro.h"
#include "mod1_main/mod1_control.h"
#include "mod1_main/mod1_generic.h"

#include "mod1_engine/namespace.h"

#include "mod1_engine/shader/shader.h"
#include "mod1_engine/uniform/uniform.h"

class					mod1_engine::program
{

public :

						program();
						~program();

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_compilation, "Mod1 Engine, Program : Compilation error")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_vertex, "Mod1 Engine, Program : Object doesn't have vertex shader")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_link, "Mod1 Engine, Program : Object is not linked")

	void				start();
	void				stop();

	GLuint				object();

	typedef enum
	{
		vertex = GL_VERTEX_SHADER,
		geometry = GL_GEOMETRY_SHADER,
		fragment = GL_FRAGMENT_SHADER,
		compute = GL_COMPUTE_SHADER
	}					shader_type;

	void 				add_shader(const shader_type &type, const char *source);
	void 				link();

private :

	bool				has_vertex_shader = false;
	bool				is_linked = false;

	GLuint 				object_internal;

	void 				check_error();

};
