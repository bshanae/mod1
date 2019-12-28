#pragma once

#include "mod1_OpenGL.h"
#include "mod1_model_data.h"

#include <vector>

class							mod1_loader
{

public :

								mod1_loader() = default;
								~mod1_loader();

	void 						load(mod1_model_data &data);

	GLuint						vbo_build();
	static void					vbo_bind(GLuint vbo);
	static void					vbo_unbind();

	template					<typename type>
	void 						vbo_buffer(GLuint vbo, const mod1_buffer<type> &buffer)
	{
		vbo_bind(vbo);
		glBufferData(GL_ARRAY_BUFFER, buffer.size_in_bytes(), buffer.data(), GL_STATIC_DRAW);
		vbo_unbind();
	}

	GLuint						vao_build();
	static void					vao_bind(GLuint vao);
	static void					vao_unbind();

	template					<typename type>
	GLuint 						vao_edit_attribute(GLuint vao, int attribute, int element_size, GLenum gl_type, const mod1_buffer<type> &buffer)
	{
		GLuint				vbo;

		vbo = vbo_build();
		vao_bind(vao);
		vbo_buffer(vbo, buffer);
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
	void 						eab_buffer(GLuint eab, const mod1_buffer<type> &buffer)
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


