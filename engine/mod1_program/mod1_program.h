#pragma once

#include "mod1_OpenGL.h"
#include "mod1_const.h"
#include "mod1_exception.h"

#include "mod1_shader.h"

class					mod1_program
{

public :

						mod1_program();
						~mod1_program();

	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_compilation, "Mod1 Program : Compilation error")

	void				start();
	void				stop();

	GLuint				object();

private :

	GLuint 				object_internal;
};
