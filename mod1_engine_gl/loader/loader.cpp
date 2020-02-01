#include "loader.h"

using namespace			mod1_engine_gl;

						loader::~loader()
{
	unsigned int		*object = nullptr;

	for (int i = 0; i < vbo_vector.size() && (object = &vbo_vector.at(i)); i++)
		glDeleteBuffers(1, object);
	for (int i = 0; i < vbo_vector.size() && (object = &vbo_vector.at(i)); i++)
		glDeleteBuffers(1, object);
	for (int i = 0; i < vbo_vector.size() && (object = &vbo_vector.at(i)); i++)
		glDeleteBuffers(1, object);
}

void					loader::load(model_data &data, const bool &is_dynamic)
{
	unsigned int 		eab = eab_build();

	data.vao = vao_build();

	vao_bind(data.vao);
	eab_bind(eab);

	data.vbo_point = vao_attribute(data.vao, 0, 3, GL_FLOAT, data.point_buffer, is_dynamic);

	eab_buffer(eab, data.index_buffer);
	loader::eab_unbind();

	if (data.normal_buffer.is_allocated())
		data.vbo_normal = vao_attribute(data.vao, 1, 3, GL_FLOAT, data.normal_buffer, is_dynamic);
	if (data.color_buffer.is_allocated())
		data.vbo_color = vao_attribute(data.vao, 2, 3, GL_FLOAT, data.color_buffer, is_dynamic);

	loader::vao_unbind();
}
