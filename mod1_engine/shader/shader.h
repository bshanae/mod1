#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_generic.h"

#include "mod1_engine/namespace.h"

#include <string>
#include <fstream>
#include <sstream>

class					mod1_engine::shader
{

public :

						shader() = default;
						~shader();

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_source, "Mod1 Shader : Invalid source file")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_compilation, "Mod1 Shader : Compilation error")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_build, "Mod1 Shader : Object is not built")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_link, "Mod1 Shader : Object is not linked")


	void				build(int type, const char *source);
	void				link(const GLuint &program_id);

	GLuint				object();

private :

	bool				is_build = false;
	bool				is_linked = false;
	GLuint 				object_internal = -1;

	static std::string	read_source(const char *path);
};
