#include "texture.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, width)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, height)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(texture, object)

					texture::texture(const texture_type &type_mod1, const int &width, const int &height)
{
	MOD1_INTERNAL(width) = width;
	MOD1_INTERNAL(height) = height;

	glGenTextures(1, &MOD1_INTERNAL(object));

	bind();

	switch (type_mod1)
	{
		case texture_type::color :
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
				width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
			break;
		case texture_type::depth :
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24,
				width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
			break;
		default :
			throw (exception_enum());
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	unbind();
}

					texture::~texture()
{
	glDeleteTextures(1, &MOD1_INTERNAL(object));
}

void				texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, MOD1_INTERNAL(object));
}

void				texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void				texture::activate(const int &index)
{
	glActiveTexture(GL_TEXTURE0 + index);
}