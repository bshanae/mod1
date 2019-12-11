#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"

#include <string>
#include <fstream>
#include <sstream>

class					mod1_shader
{

public :

						mod1_shader(int type, const std::string &source);
						~mod1_shader();

	GLuint				get_object();

private :

	static std::string	shader_read_source(const std::string &path);

	GLuint 				object;
};
