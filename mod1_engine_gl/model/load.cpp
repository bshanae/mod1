#include "model.h"

using namespace		mod1_engine_gl;

void				model::load()
{
	eab = new class eab;

	vao = new class vao;

	vao->bind();
	eab->bind();

	vbo_point = vao->attribute(3, point_buffer, is_dynamic);

	eab->buffer(index_buffer);

	eab::unbind();

	if (normal_buffer.is_allocated())
		vbo_normal = vao->attribute(3, normal_buffer, is_dynamic);
	if (color_buffer.is_allocated())
		vbo_color = vao->attribute(3, color_buffer, is_dynamic);

	vao::unbind();

	is_loaded = true;
	vertex_number = index_buffer.size() * 3;
}