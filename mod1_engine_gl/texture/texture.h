#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/point/point2.h"

class				mod1_engine_gl::texture
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_initialization, "Mod1 Engine GL, Texture : Object is not initialized")

					texture() = default;
					texture(
					const int &width,
					const int &height,
					const GLenum &format_a,
					const GLenum &format_b);
					~texture();

	void			start() const;
	void			stop() const;

private :

	bool			is_empty = true;

MOD1_GENERATE_INTERNAL_WITH_VALUE(int, width, 0)
MOD1_GENERATE_INTERNAL_WITH_VALUE(int, height, 0)
MOD1_GENERATE_INTERNAL_WITH_VALUE(unsigned int, object, 0)

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(width)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(height)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(object)

};


