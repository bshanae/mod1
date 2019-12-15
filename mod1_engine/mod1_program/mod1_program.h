#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"
#include "mod1_shader.h"

class					mod1_program
{

public :

						mod1_program();
						~mod1_program();

	void				start();
	void				stop();

	GLuint				object();

private :

	GLuint 				object_value;
	const std::string	shader_vertex_source = "./mod1_engine/shaders/vertex.glsl";
	const std::string	shader_fragment_source = "./mod1_engine/shaders/fragment.glsl";

};
