#pragma once

#include "mod1_engine_gl/namespace.h"

class				mod1_engine_gl::vbo
{
public :
					vbo();
					~vbo();

	void			bind() const;
	static void		unbind();

	template		<typename type>
	void			buffer(const buffer<type> &buffer, const bool &is_dynamic = false)
	{
		bind();

		glBufferData(
			GL_ARRAY_BUFFER,
			buffer.size_in_bytes(),
			buffer.data(),
			is_dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);

		unbind();
	}

private :

	unsigned int	object = 0;

};


