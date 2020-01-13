#include "program.h"

using namespace		mod1_engine;

//					PUBLIC

MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(program, exception_compilation)
MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(program, exception_vertex)
MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(program, exception_link)

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

GLuint				program::object()
{
	if (not is_linked)
		throw (exception_link());

	return (object_internal);
}

//					PROTECTED

void 				program::add_shader(const shader_type &type, const char *source)
{
	shader			shader;

	shader.build(type, source);
	shader.link(object_internal);

	if (glGetError())
		exit(1);

	if (type == vertex)
		has_vertex_shader = true;
}

void 				program::link()
{
	if (not has_vertex_shader)
		throw (exception_vertex());

	glLinkProgram(object_internal);

	check_error();

	is_linked = true;
}

//					PRIVATE

void				program::start_noexcept()
{
	glUseProgram(object_internal);
}

void 				program::check_error()
{
	GLint			success;
	GLchar			log[1024];

	start_noexcept();

	glGetProgramiv(object_internal, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(object_internal, 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		throw (exception_compilation());
	}

	stop();
}
