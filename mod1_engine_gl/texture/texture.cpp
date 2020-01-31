#include "texture.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(texture, exception_initialization)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, width)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, height)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, object)

					texture::texture(const texture_type &type, const int &width, const int &height)
{
	MOD1_INTERNAL(width) = width;
	MOD1_INTERNAL(height) = height;

	GLenum			format_a;
	GLenum			format_b;

	switch (type)
	{
		case texture_type::color :
			format_a = GL_RGBA;
			format_b = GL_RGBA;
			break ;
		case texture_type::depth :
			format_a = GL_DEPTH_COMPONENT;
			format_b = GL_DEPTH_COMPONENT;
			break ;
		default :
			throw (exception_enum());
	}

	glGenTextures(1, &MOD1_INTERNAL(object));

	is_empty = false;

	start();

	glTexImage2D(GL_TEXTURE_2D, 0, format_a, width, height,
		0, format_b, GL_UNSIGNED_BYTE, nullptr);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stop();
}

					texture::~texture()
{
	glDeleteTextures(1, &MOD1_INTERNAL(object));
}

void				texture::start() const
{
	if (is_empty)
		throw (exception_initialization());

	glBindTexture(GL_TEXTURE_2D, MOD1_INTERNAL(object));
}

void				texture::stop() const
{
	if (is_empty)
		throw (exception_initialization());

	glBindTexture(GL_TEXTURE_2D, 0);
}