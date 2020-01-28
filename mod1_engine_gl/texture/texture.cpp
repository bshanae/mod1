#include "texture.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, width)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, height)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, object)

					texture::texture()
{
	glGenTextures(1, &MOD1_INTERNAL(object));
}

					texture::texture(const int &width, const int &height)
{
	glGenTextures(1, &MOD1_INTERNAL(object));
	build(width, height);
}

					texture::~texture()
{
	glDeleteTextures(1, &MOD1_INTERNAL(object));
}

void				texture::build(const int &width, const int &height)
{
	MOD1_INTERNAL(width) = width;
	MOD1_INTERNAL(height) = height;

	start();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
		0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stop();
}

void				texture::start() const
{
	glBindTexture(GL_TEXTURE_2D, MOD1_INTERNAL(object));
}

void				texture::stop() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}