#include "shader.h"

using namespace			mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(shader, exception_source)
MOD1_GENERATE_EXCEPTION_DEFINITION(shader, exception_compilation)
MOD1_GENERATE_EXCEPTION_DEFINITION(shader, exception_build)
MOD1_GENERATE_EXCEPTION_DEFINITION(shader, exception_link)

						shader::~shader()
{
	glDeleteShader(object_internal);
}

void					shader::build(const shader_type &type, const char *source)
{
	std::string			string;
	const char 			*ptr;

	object_internal = glCreateShader((GLuint)type);
	string = read_source(source);
	ptr = string.c_str();

	glShaderSource(object_internal, 1, &ptr, nullptr);
	glCompileShader(object_internal);

	GLint				success;
	GLchar				log[1024];

	glGetShaderiv(object_internal, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(object_internal, 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		throw (exception_compilation());
	}

	is_build = true;
}

void					shader::link(const GLuint &program_id)
{
	if (!is_build)
		throw (exception_build());

	glAttachShader(program_id, object_internal);

	is_linked = true;
}

GLuint					shader::object()
{
	if (!is_build)
		throw (exception_build());
	if (!is_linked)
		throw (exception_link());

	return (object_internal);
}

std::string				shader::read_source(const char *path)
{
	std::ifstream		file;
	std::stringstream	stream;
	std::string			string;

	file.open(path);

	if (!file.is_open())
		throw (exception_source());

	stream << file.rdbuf();

	file.close();
	string = stream.str();

	return (string);
}