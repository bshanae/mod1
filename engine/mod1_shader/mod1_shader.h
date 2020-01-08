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
						~mod1_shader();

	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_source, "Mod1 Shader : Invalid source file")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_compilation, "Mod1 Shader : Compilation error")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_build, "Mod1 Shader : Object is not built")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_link, "Mod1 Shader : Object is not linked")


	void				build(int type, const char *source);
	void				link(const GLuint &program_id);

	GLuint				object();

private :

	bool				is_build = false;
	bool				is_linked = false;
	GLuint 				object_internal = -1;

	static std::string	read_source(const char *path);
};
