#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"
#include "mod1_shader.h"

class					mod1_program
{

public :

	explicit mod1_program(const mod1_error &error);

	~mod1_program();

	GLuint				get_object() const;

private :

	const mod1_error	&error;
	GLuint 				object;
	const std::string	shader_vertex_source = "./shaders/vertex.glsl";
	const std::string	shader_fragment_source = "./shaders/fragment.glsl";

};
