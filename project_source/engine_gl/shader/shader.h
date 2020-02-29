#pragma once

#include "engine_gl/namespace.h"


enum class				mod1_engine_gl::shader_type
{
	vertex = GL_VERTEX_SHADER,
	geometry = GL_GEOMETRY_SHADER,
	fragment = GL_FRAGMENT_SHADER
};

class					mod1_engine_gl::shader
{

public :

						shader() = default;
						~shader();

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_source, "Mod1 Engine GL, Shader : Invalid source file")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_compilation, "Mod1 Engine GL, Shader : Compilation error")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_build, "Mod1 Engine GL, Shader : Object is not built")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_link, "Mod1 Engine GL, Shader : Object is not linked")

	void				build(const shader_type &type, const char *source);
	void				link(const unsigned int &program_id);

private :

	bool				is_built = false;
	bool				is_linked = false;

MOD1_GENERATE_INTERNAL_WITH_VALUE(unsigned int, object, 0)

	static std::string	read_source(const char *path);

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(object)
};
