#include "mod1_program.h"

					mod1_program::mod1_program()
{
	mod1_shader		shader_vertex(GL_VERTEX_SHADER, MOD1_SOURCE_SHADER_VERTEX);
	mod1_shader		shader_fragment(GL_FRAGMENT_SHADER, MOD1_SOURCE_SHADER_FRAGMENT);

	object_internal = glCreateProgram();
	glAttachShader(object_internal, shader_vertex.object());
	glAttachShader(object_internal, shader_fragment.object());
	glLinkProgram(object_internal);
	glUseProgram(object_internal);

	GLint				success;
	GLchar				log[1024];

	glGetProgramiv(object_internal, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(object_internal, 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		throw (exception_compilation());
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

const char			*mod1_program::exception_compilation::what() const noexcept
{
	return ("Mod1 Program : Compilation error");
}