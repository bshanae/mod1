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

	GLuint			object() const;

	void			save(const char *file) const;

private :

	point2<int>		resolution;
	GLuint			object_internal = 0;

};


