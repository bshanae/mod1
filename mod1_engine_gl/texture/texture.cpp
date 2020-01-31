#include "texture.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(texture, exception_initialization)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, width)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, height)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, object)

					texture::texture(
					const int &width,
					const int &height,
					const GLenum &format_a,
					const GLenum &format_b)
{
	MOD1_INTERNAL(width) = width;
	MOD1_INTERNAL(height) = height;

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