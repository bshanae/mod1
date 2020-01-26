#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/model/model_data.h"

class							mod1_engine_gl::loader
{

public :

								loader() = default;
								~loader();

	void 						load(model_data &data, const bool &is_dynamic);

	GLuint						vbo_build();
	static void					vbo_bind(GLuint vbo);
	static void					vbo_unbind();

	template					<typename type>
	static void 				vbo_buffer(GLuint vbo, const buffer<type> &buffer, const bool &is_dynamic)
	{
		vbo_bind(vbo);
		glBufferData(
			GL_ARRAY_BUFFER,
			buffer.size_in_bytes(),
			buffer.data(),
			is_dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		vbo_unbind();
	}

	GLuint						vao_build();
	static void					vao_bind(GLuint vao);
	static void					vao_unbind();

	template					<typename type>
	GLuint 						vao_edit_attribute(
								GLuint vao,
								int attribute,
								int element_size,
								GLenum gl_type,
								const buffer<type> &buffer,
								const bool &is_dynamic)
	{
		GLuint					vbo;

		vbo = vbo_build();
		vao_bind(vao);
		vbo_buffer(vbo, buffer, is_dynamic);
		vbo_bind(vbo);
		glVertexAttribPointer(attribute, element_size, gl_type, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
		glEnableVertexAttribArray(attribute);
		vbo_unbind();
		vao_unbind();

		return (vbo);
	}

	GLuint						eab_build();
	static void					eab_bind(GLuint eab);
	static void					eab_unbind();

	template					<typename type>
	void 						eab_buffer(GLuint eab, const buffer<type> &buffer)
	{
		eab_bind(eab);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, buffer.size_in_bytes(), buffer.data(), GL_STATIC_DRAW);
		eab_unbind();
	}

private :

	std::vector<GLuint>			vbo_vector;
	std::vector<GLuint>			vao_vector;
	std::vector<GLuint>			eab_vector;
};


