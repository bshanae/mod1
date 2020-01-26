#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/point/point2.h"

class				mod1_engine_gl::texture
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_built,
	"Mod1 Engine GL, Texture : Object is not built")

					texture();
					texture(const int &width, const int &height);
					~texture();

	void			build(const int &width, const int &height);

	void			start();
	void			stop();

	GLuint			object() const;

private :

	bool 			is_built = false;

	point2<int>		resolution;
	GLuint			object_internal = 0;

};


