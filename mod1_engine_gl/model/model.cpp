#include "model.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_build)
MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_load)
MOD1_GENERATE_EXCEPTION_DEFINITION(model, exception_dynamic)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(model, transformation)

void				model::load(loader &loader)
{
	is_loaded = true;
	loader.load(data, is_dynamic);
	vertex_number = data.index_buffer.size() * 3;
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
	loader::vao_bind(data.vao);
}

void				model::stop() const
{
	loader::vao_unbind();
}

void				*model::get_ptr(const int &index, const model_data::slot_type &slot)
{
	return (data.get_ptr(index, slot));
}

void const			*model::get_ptr(const int &index, const model_data::slot_type &slot) const
{
	return (data.get_ptr(index, slot));
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

void				model::upload_buffer(const model_data::slot_type &slot)
{
	if (slot == model_data::slot_type::point)
		loader::vbo_buffer(data.vbo_point, data.point_buffer, is_dynamic);
	else if (slot == model_data::slot_type::normal)
		loader::vbo_buffer(data.vbo_normal, data.normal_buffer, is_dynamic);
	else if (slot == model_data::slot_type::color)
		loader::vbo_buffer(data.vbo_color, data.color_buffer, is_dynamic);
	else
		throw (exception_enum());
}