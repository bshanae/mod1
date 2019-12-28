#include "mod1_loader.h"

						mod1_loader::~mod1_loader()
{
	const GLuint 		*object;

	object = nullptr;
	for (int i = 0; i < vbo_vector.size() && (object = &vbo_vector.at(i)); i++)
		glDeleteBuffers(1, object);
	for (int i = 0; i < vbo_vector.size() && (object = &vbo_vector.at(i)); i++)
		glDeleteBuffers(1, object);
	for (int i = 0; i < vbo_vector.size() && (object = &vbo_vector.at(i)); i++)
		glDeleteBuffers(1, object);
}

void					mod1_loader::load(mod1_model_data &data)
{
	GLuint 				eab = eab_build();

	data.vao = vao_build();

	vao_bind(data.vao);
	eab_bind(eab);

	data.vbo_point = vao_edit_attribute(data.vao, 0, 3, GL_FLOAT, data.point_buffer);

	eab_buffer(eab, data.index_buffer);
	mod1_loader::eab_unbind();

	data.vbo_normal = vao_edit_attribute(data.vao, 1, 3, GL_FLOAT, data.normal_buffer);
	data.vbo_color = vao_edit_attribute(data.vao, 2, 3, GL_FLOAT, data.color_buffer);

	mod1_loader::vao_unbind();
}
