#pragma once

#include "engine_gl/namespace.h"

#include "engine_gl/buffer/buffer.h"

class				mod1_engine_gl::eab
{
public :

					eab();
					~eab();

	void			bind() const;
	static void 	unbind();

	template		<typename type>
	void 			buffer(const buffer<type> &buffer)
	{
		bind();
		glBufferData(
			GL_ELEMENT_ARRAY_BUFFER,
			buffer.size_in_bytes(),
			buffer.data(),
			GL_STATIC_DRAW);
		unbind();
	}

private :

	unsigned int	object = 0;
};


