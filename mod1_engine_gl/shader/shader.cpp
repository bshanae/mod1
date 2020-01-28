#include "shader.h"

using namespace			mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(shader, exception_source)
MOD1_GENERATE_EXCEPTION_DEFINITION(shader, exception_compilation)
MOD1_GENERATE_EXCEPTION_DEFINITION(shader, exception_build)
MOD1_GENERATE_EXCEPTION_DEFINITION(shader, exception_link)

						shader::~shader()
{
	glDeleteShader(MOD1_INTERNAL(object));
}

void					shader::build(const shader_type &type, const char *source)
{
	std::string			string;
	const char 			*ptr;

	MOD1_INTERNAL(object) = glCreateShader((unsigned int)type);
	string = read_source(source);
	ptr = string.c_str();

	glShaderSource(MOD1_INTERNAL(object), 1, &ptr, nullptr);
	glCompileShader(MOD1_INTERNAL(object));

	GLint				success;
	GLchar				log[1024];

	glGetShaderiv(MOD1_INTERNAL(object), GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(MOD1_INTERNAL(object), 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		throw (exception_compilation());
	}

	is_built = true;
}

void					shader::link(const unsigned int &program_id)
{
	if (!is_built)
		throw (exception_build());

	glAttachShader(program_id, MOD1_INTERNAL(object));

	is_linked = true;
}

unsigned int			shader::object() const
{
	if (!is_built)
		throw (exception_build());
	if (!is_linked)
		throw (exception_link());

	return (MOD1_INTERNAL(object));
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