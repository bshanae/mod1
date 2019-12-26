#include "mod1_shader.h"

						mod1_shader::mod1_shader(int type, const std::string &source)
{
	std::string			string;
	const char 			*ptr;

	object = glCreateShader(type);
	string = shader_read_source(source);
	ptr = string.c_str();

	glShaderSource(object, 1, &ptr, nullptr);
	glCompileShader(object);

	GLint				success;
	GLchar				log[1024];

	glGetShaderiv(object, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(object, 1024, nullptr, log);
		printf("Log : \n%s\n", log);
		throw (exception_compilation());
	}
}

						mod1_shader::~mod1_shader()
{
	glDeleteShader(object);
}

GLuint					mod1_shader::get_object()
{
	return (object);
}

std::string				mod1_shader::shader_read_source(const std::string &path)
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

const char			*mod1_shader::exception_source::what() const noexcept
{
	return ("Mod1 Shader : Invalid source file");
}

const char			*mod1_shader::exception_compilation::what() const noexcept
{
	return ("Mod1 Shader : Compilation error");
}