#include "program.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(program, exception_compilation)
MOD1_GENERATE_EXCEPTION_DEFINITION(program, exception_link)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(program, object)

					program::program()
{
	MOD1_INTERNAL(object) = glCreateProgram();
}

					program::~program()
{
	glDeleteProgram(MOD1_INTERNAL(object));
}

void				program::start()
{
	if (not is_linked)
		throw (exception_link());
	glUseProgram(MOD1_INTERNAL(object));
}

void				program::stop()
{
	glUseProgram(0);
}

void 				program::add_shader(const shader_type &type, const char *source)
{
	shader			shader;

	shader.build(type, source);
	shader.link(MOD1_INTERNAL(object));
}

void				program::link()
{
	glLinkProgram(MOD1_INTERNAL(object));
	is_linked = true;
	check_error();
}

void 				program::set_uniform(uniform &uniform)
{
	uniform.set(MOD1_INTERNAL(object));
}

void				program::check_error()
{
	GLint			success;
	GLchar			log[1024];

	glGetProgramiv(MOD1_INTERNAL(object), GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(MOD1_INTERNAL(object), 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		throw (exception_compilation());
	}
}