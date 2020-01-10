#pragma once

#include "mod1_OpenGL.h"
#include "mod1_macros.h"
#include "mod1_generate_x.h"

#include "mod1_shader.h"

class					mod1_program
{

public :

						mod1_program();
						~mod1_program();

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_compilation, "Mod1 Program : Compilation error")

	void				start();
	void				stop();

	GLuint				object();

private :

	GLuint 				object_internal;
};
