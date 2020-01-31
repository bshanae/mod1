#include "texture.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, width)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, height)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, object)

					texture::texture(const texture_type &type_mod1, const int &width, const int &height)
{
	MOD1_INTERNAL(width) = width;
	MOD1_INTERNAL(height) = height;

	GLenum			format_a;
	GLenum			format_b;
	GLenum			type_gl;

	switch (type_mod1)
	{
		case texture_type::color :
			format_a = GL_RGBA8;
			format_b = GL_RGBA;
			type_gl = GL_UNSIGNED_BYTE;
			break ;
		case texture_type::depth :
			format_a = GL_DEPTH_COMPONENT24;
			format_b = GL_DEPTH_COMPONENT;
			type_gl = GL_FLOAT;
			break ;
		default :
			throw (exception_enum());
	}

	glGenTextures(1, &MOD1_INTERNAL(object));

	is_empty = false;

	start();

	glTexImage2D(GL_TEXTURE_2D, 0, format_a, width, height, 0, format_b, type_gl, nullptr);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stop();
}

					texture::~texture()
{
	if (not is_empty)
		glDeleteTextures(1, &MOD1_INTERNAL(object));
}

void				texture::start() const
{
	glBindTexture(GL_TEXTURE_2D, MOD1_INTERNAL(object));
}

void				texture::stop() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}