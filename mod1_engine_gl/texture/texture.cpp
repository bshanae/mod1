#include "texture.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(texture, exception_built)

					texture::texture()
{
	glGenTextures(1, &object_internal);
}

					texture::texture(const int &width, const int &height) :
					texture()
{
	build(width, height);
}

					texture::~texture()
{
	glDeleteTextures(1, &object_internal);
}

void				texture::build(const int &width, const int &height)
{
	start();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
		0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stop();

	resolution = point2<int>(width, height);
	is_built = true;
}

void				texture::start()
{
	glBindTexture(GL_TEXTURE_2D, object_internal);
}

void				texture::stop()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint				texture::object() const
{
	return (object_internal);
}