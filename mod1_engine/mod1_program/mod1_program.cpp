#include "mod1_program.h"

					mod1_program::mod1_program()
{
	mod1_shader		shader_vertex(GL_VERTEX_SHADER, shader_vertex_source);
	mod1_shader		shader_fragment(GL_FRAGMENT_SHADER, shader_fragment_source);

	object_value = glCreateProgram();
	glAttachShader(object_value, shader_vertex.get_object());
	glAttachShader(object_value, shader_fragment.get_object());
	glLinkProgram(object_value);
	glUseProgram(object_value);

	GLint				success;
	GLchar				log[1024];

	glGetProgramiv(object_value, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(object_value, 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		global_error->raise_error("Program : Can't compile program");
	}
}

					mod1_program::~mod1_program()
{
	glDeleteProgram(object_value);
}

void				mod1_program::start()
{
	glUseProgram(object_value);
}

void				mod1_program::stop()
{
	glUseProgram(0);
}

GLuint				mod1_program::object()
{
	return (object_value);
}