#include "model.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_build)
MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_load)
MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_dynamic)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(model, transformation)

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

void				model::draw(core &core)
{
	start();
	core.draw(vertex_number);
	stop();
}

void				model::start() const
{
	if (!is_built)
		throw (exception_build());
	if (!is_loaded)
		throw (exception_load());
	vao->bind();
}

void				model::stop() const
{
	vao::unbind();
}

void 				model::set_as_built()
{
	is_built = true;
}

void 				model::set_as_dynamic()
{
	if (is_built)
		throw (exception_dynamic());
	is_dynamic = true;
}


void 				*model::pointer(const int &index, const model_slot &slot)
{
	if (slot == model_slot::point)
		return (&point_buffer[3 * index]);
	else if (slot == model_slot::index)
		return (&index_buffer[3 * index]);
	else if (slot == model_slot::normal)
		return (&normal_buffer[3 * index]);
	else if (slot == model_slot::color)
		return (&color_buffer[3 * index]);
	else
		throw (exception_enum());
}

void const			*model::pointer(const int &index, const model_slot &slot) const
{
	if (slot == model_slot::point)
		return (&point_buffer[3 * index]);
	else if (slot == model_slot::index)
		return (&index_buffer[3 * index]);
	else if (slot == model_slot::normal)
		return (&normal_buffer[3 * index]);
	else if (slot == model_slot::color)
		return (&color_buffer[3 * index]);
	else
		throw (exception_enum());
}

void				model::upload_buffer(const model_slot &slot)
{
	if (slot == model_slot::point)
		vbo_point->buffer(point_buffer, is_dynamic);
	else if (slot == model_slot::normal)
		vbo_normal->buffer(normal_buffer, is_dynamic);
	else if (slot == model_slot::color)
		vbo_color->buffer(color_buffer, is_dynamic);
	else
		throw (exception_enum());
}