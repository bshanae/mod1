#include "mod1_model.h"

MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(mod1_model, exception_build)
MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(mod1_model, exception_load)
MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(mod1_model, exception_dynamic)

void				mod1_model::load(mod1_loader &loader)
{
	is_loaded = true;
	loader.load(data, is_dynamic);
	vertex_number_internal = data.index_buffer.size() * 3;
}

void				mod1_model::use()
{
	if (!is_built)
		throw (exception_build());
	if (!is_loaded)
		throw (exception_load());
	mod1_loader::vao_bind(data.vao);
}

int 				mod1_model::vertex_number()
{
	return (vertex_number_internal);
}

glm::mat4			&mod1_model::transformation()
{
	return (transformation_internal);
}

void				*mod1_model::get_ptr(const int &index, const mod1_model_data::slot_type &slot)
{
	return (data.get_ptr(index, slot));
}

void const			*mod1_model::get_ptr(const int &index, const mod1_model_data::slot_type &slot) const
{
	return (data.get_ptr(index, slot));
}

void 				mod1_model::set_as_built()
{
	is_built = true;
}

void 				mod1_model::set_as_dynamic()
{
	if (is_built)
		throw (exception_dynamic());
	is_dynamic = true;
}

void				mod1_model::upload_buffer(const mod1_model_data::slot_type &slot)
{
	if (slot == mod1_model_data::slot_point)
		mod1_loader::vbo_buffer(data.vbo_point, data.point_buffer, is_dynamic);
	else if (slot == mod1_model_data::slot_normal)
		mod1_loader::vbo_buffer(data.vbo_normal, data.normal_buffer, is_dynamic);
	else if (slot == mod1_model_data::slot_color)
		mod1_loader::vbo_buffer(data.vbo_color, data.color_buffer, is_dynamic);
	else
		throw (mod1_model_data::exception_unknown_slot());
}