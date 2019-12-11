#include "mod1_program.h"

					mod1_program::mod1_program()
{
	mod1_shader		shader_vertex(GL_VERTEX_SHADER, shader_vertex_source);
	mod1_shader		shader_fragment(GL_FRAGMENT_SHADER, shader_fragment_source);

	object = glCreateProgram();
	glAttachShader(object, shader_vertex.get_object());
	glAttachShader(object, shader_fragment.get_object());
	glLinkProgram(object);
	glUseProgram(object);

	GLint				success;
	GLchar				log[1024];

	glGetProgramiv(object, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(object, 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		global_error->raise_error("Program : Can't compile program");
	}
}

					mod1_program::~mod1_program()
{
	glDeleteProgram(object);
}

void				mod1_program::start()
{
	glUseProgram(object);
}

void				mod1_program::stop()
{
	glUseProgram(0);
}