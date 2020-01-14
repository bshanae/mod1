#include "program.h"

using namespace		mod1_engine;

MOD1_GENERATE_EXCEPTION_DEFINITION(program, exception_compilation)
MOD1_GENERATE_EXCEPTION_DEFINITION(program, exception_link)

					program::program()
{
	object_internal = glCreateProgram();
}

					program::~program()
{
	glDeleteProgram(object_internal);
}

void				program::start()
{
	if (not is_linked)
		throw (exception_link());
	glUseProgram(object_internal);
}

void				program::stop()
{
	glUseProgram(0);
}

void 				program::add_shader(const shader_type &type, const char *source)
{
	shader			shader;

	shader.build(type, source);
	shader.link(object_internal);
}

void				program::link()
{
	glLinkProgram(object_internal);
	is_linked = true;
	check_error();
}

GLuint				program::object()
{
	return (object_internal);
}

void				program::check_error()
{
	GLint			success;
	GLchar			log[1024];

	glGetProgramiv(object_internal, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(object_internal, 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		throw (exception_compilation());
	}
}