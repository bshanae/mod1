#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/point/point2.h"

class				mod1_engine_gl::texture
{
public :

					texture();
					texture(const int &width, const int &height);
					~texture();

	void			build(const int &width, const int &height);

	void			start() const;
	void			stop() const;

private :

MOD1_GENERATE_INTERNAL_WITH_VALUE(int, width, 0)
MOD1_GENERATE_INTERNAL_WITH_VALUE(int, height, 0)
MOD1_GENERATE_INTERNAL_WITH_VALUE(unsigned int, object, 0)

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(width)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(height)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(object)

};


