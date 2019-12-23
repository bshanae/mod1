#include "mod1_program.h"

					mod1_program::mod1_program()
{
	mod1_shader		shader_vertex(GL_VERTEX_SHADER, shader_vertex_source);
	mod1_shader		shader_fragment(GL_FRAGMENT_SHADER, shader_fragment_source);

	object_internal = glCreateProgram();
	glAttachShader(object_internal, shader_vertex.get_object());
	glAttachShader(object_internal, shader_fragment.get_object());
	glLinkProgram(object_internal);
	glUseProgram(object_internal);

	GLint				success;
	GLchar				log[1024];

	glGetProgramiv(object_internal, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(object_internal, 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		global_error->raise_error("Program : Can't compile program");
	}
}

					mod1_program::~mod1_program()
{
	glDeleteProgram(object_internal);
}

void				mod1_program::start()
{
	glUseProgram(object_internal);
}

void				mod1_program::stop()
{
	glUseProgram(0);
}

GLuint				mod1_program::object()
{
	return (object_internal);
}