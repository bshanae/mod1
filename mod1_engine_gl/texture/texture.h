#pragma once

#include "mod1_engine_gl/namespace.h"

enum class			mod1_engine_gl::texture_type
{
	color,
	depth
};

class				mod1_engine_gl::texture
{
public :

					texture(const texture_type &type, const int &width, const int &height);
					~texture();

	void			bind() const;
	static void		unbind();

	static void		activate(const int &index = 0);

private :

MOD1_GENERATE_INTERNAL_WITH_VALUE(int, width, 0)
MOD1_GENERATE_INTERNAL_WITH_VALUE(int, height, 0)
MOD1_GENERATE_INTERNAL_WITH_VALUE(unsigned int, object, 0)

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(width)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(height)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(object)

};


