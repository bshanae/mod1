#include "mod1_program.h"

#include "mod1_control.h"

MOD1_EXCEPTION_GENERATE_IMPLEMENTATION(mod1_program, exception_compilation)

					mod1_program::mod1_program()
{
	mod1_shader		shader_vertex;
	mod1_shader		shader_geometry;
	mod1_shader		shader_fragment;

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
