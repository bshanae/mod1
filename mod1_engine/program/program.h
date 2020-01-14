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

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_compilation, "Mod1 Program : Compilation error")

	void				start();
	void				stop();

	GLuint				object();

private :

	GLuint 				object_internal;
};
