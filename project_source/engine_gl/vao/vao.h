#pragma once

#include "engine_gl/namespace.h"

#include "engine_gl/vbo/vbo.h"

class					mod1_engine_gl::vao
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_template, "Mod1 Engine GL, VAO : Type of input buffer is unacceptable")

						vao();
						~vao();

	void				bind() const;
	static void			unbind();

	template			<typename type>
	vbo					*attribute(
						const int &element_size,
						const buffer<type> &buffer,
						const bool &is_dynamic = false)
	{
		attribute_vector.push_back(new vbo);

		vbo				*vbo = attribute_vector.back();
		GLenum			data_type;

		if (std::is_same<type, unsigned int>::value)
			data_type = GL_UNSIGNED_INT;
		else if (std::is_same<type, float>::value)
			data_type = GL_FLOAT;
		else
			throw (exception_template());

		bind();

		vbo->buffer(buffer, is_dynamic);
		vbo->bind();
		glVertexAttribPointer(
			attribute_count,
			element_size,
			data_type,
			GL_FALSE,
			element_size * sizeof(type),
			nullptr);
		glEnableVertexAttribArray(attribute_count++);
		vbo::unbind();
		unbind();

		return (vbo);
	}

private :

	unsigned int		object = 0;

	int 				attribute_count = 0;
	std::vector<vbo *>	attribute_vector;
};


