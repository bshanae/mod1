#include "loader.h"

using namespace			mod1_engine_gl;

						loader::~loader()
{
	const unsigned int 		*object;

	object = nullptr;
	for (int i = 0; i < vbo_vector.size() && (object = &vbo_vector.at(i)); i++)
		glDeleteBuffers(1, object);
	for (int i = 0; i < vbo_vector.size() && (object = &vbo_vector.at(i)); i++)
		glDeleteBuffers(1, object);
	for (int i = 0; i < vbo_vector.size() && (object = &vbo_vector.at(i)); i++)
		glDeleteBuffers(1, object);
}

void					loader::load(model_data &data, const bool &is_dynamic)
{
	unsigned int 				eab = eab_build();

	data.vao = vao_build();

	vao_bind(data.vao);
	eab_bind(eab);

	data.vbo_point = vao_edit_attribute(data.vao, 0, 3, GL_FLOAT, data.point_buffer, is_dynamic);

	eab_buffer(eab, data.index_buffer);
	loader::eab_unbind();

	data.vbo_normal = vao_edit_attribute(data.vao, 1, 3, GL_FLOAT, data.normal_buffer, is_dynamic);
	data.vbo_color = vao_edit_attribute(data.vao, 2, 3, GL_FLOAT, data.color_buffer, is_dynamic);

	loader::vao_unbind();
}
