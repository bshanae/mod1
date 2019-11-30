#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"

#include <string>
#include <fstream>
#include <sstream>

class				mod1_shader
{

public :

	mod1_shader(const mod1_error& error, int type, const std::string &source);

	~mod1_shader();

	GLuint				get_object();

private :

	std::string			shader_read_source(const std::string &path);

	const mod1_error	&error;
	GLuint 				object;

};
