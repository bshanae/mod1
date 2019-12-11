#pragma once

#include "mod1_OpenGL.h"
#include "mod1_model_data.h"

#include <vector>

class							mod1_loader
{

public :

								mod1_loader() = default;

								~mod1_loader();

	void 						load(const mod1_model_data &data, GLuint &vao, GLuint &eab);

	GLuint						vbo_build();
	static void					vbo_bind(GLuint vbo);
	static void					vbo_unbind();
	static void 				vbo_buffer(GLuint vbo, const void *data, int data_size);

	GLuint						vao_build();
	static void					vao_bind(GLuint vao);
	static void					vao_unbind();
	void 						vao_edit_attribute(GLuint vao, int attribute, int element_size, GLenum type, const void *data, int data_size);

	GLuint						eab_build();
	static void					eab_bind(GLuint eab);
	static void					eab_unbind();
	static void 				eab_buffer(GLuint eab, const void *data, int data_size);

private :

	std::vector<GLuint>			vbo_vector;
	std::vector<GLuint>			vao_vector;
	std::vector<GLuint>			eab_vector;
};


