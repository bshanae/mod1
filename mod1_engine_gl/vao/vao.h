#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/vbo/vbo.h"

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

		vbo				*vbo = attribute_vector.back(); MOD1_GENERATE_GL_TEST
		GLenum			data_type;

		if (std::is_same<type, unsigned int>::value)
			data_type = GL_UNSIGNED_INT;
		else if (std::is_same<type, float>::value)
			data_type = GL_FLOAT;
		else
			throw (exception_template());

		bind();

		vbo->buffer(buffer, is_dynamic); MOD1_GENERATE_GL_TEST
		vbo->bind(); MOD1_GENERATE_GL_TEST
		glVertexAttribPointer(
			attribute_count,
			element_size,
			data_type,
			GL_FALSE,
			element_size * sizeof(type),
			nullptr); MOD1_GENERATE_GL_TEST
		glEnableVertexAttribArray(attribute_count++); MOD1_GENERATE_GL_TEST
		vbo::unbind(); MOD1_GENERATE_GL_TEST
		unbind(); MOD1_GENERATE_GL_TEST

		return (vbo);
	}

private :

	unsigned int		object = 0;

	int 				attribute_count = 0;
	std::vector<vbo *>	attribute_vector;
};


