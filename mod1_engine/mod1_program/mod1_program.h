#pragma once

#include "mod1_OpenGL.h"
#include "mod1_shader.h"

class					mod1_program
{

public :

						mod1_program();
						~mod1_program();

	struct				exception_compilation : public std::exception
	{
		const char		*what() const noexcept override;
	};

	void				start();
	void				stop();

	GLuint				object();

private :

	GLuint 				object_internal;
	const std::string	shader_vertex_source = "./shaders/vertex.glsl";
	const std::string	shader_fragment_source = "./shaders/fragment.glsl";
};
