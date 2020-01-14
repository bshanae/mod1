#include "program.h"

using namespace		mod1_engine;

MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(program, exception_compilation)

					program::program()
{
	shader			shader_vertex;
	shader			shader_geometry;
	shader			shader_fragment;

	object_internal = glCreateProgram();

	shader_vertex.build(GL_VERTEX_SHADER, MOD1_SOURCE_SHADER_VERTEX);
#if MOD1_NORMAL_TEST
	shader_geometry.build(GL_GEOMETRY_SHADER, MOD1_SOURCE_SHADER_GEOMETRY);
#endif
	shader_fragment.build(GL_FRAGMENT_SHADER, MOD1_SOURCE_SHADER_FRAGMENT);

	shader_vertex.link(object_internal);
#if MOD1_NORMAL_TEST
	shader_geometry.link(object_internal);
#endif
	shader_fragment.link(object_internal);

	glLinkProgram(object_internal);
	glUseProgram(object_internal);

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

					program::~program()
{
	glDeleteProgram(object_internal);
}

void				program::start()
{
	glUseProgram(object_internal);
}

void				program::stop()
{
	glUseProgram(0);
}

GLuint				program::object()
{
	return (object_internal);
}
