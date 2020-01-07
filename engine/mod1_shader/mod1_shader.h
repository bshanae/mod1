#pragma once

#include "mod1_OpenGL.h"
#include "mod1_exception.h"

#include <string>
#include <fstream>
#include <sstream>

class					mod1_shader
{

public :

						mod1_shader() = default;
						mod1_shader(int type, const char *source);
						~mod1_shader();

	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_source, "Mod1 Shader : Invalid source file")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_compilation, "Mod1 Shader : Compilation error")

	GLuint				object();

private :

	static std::string	read_source(const char *path);

	GLuint 				object_internal;
};
