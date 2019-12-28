#include "mod1_model.h"

const char			*mod1_model::exception_not_built::what() const noexcept
{
	return ("Mod1 Model : Not built");
}

const char			*mod1_model::exception_not_loaded::what() const noexcept
{
	return ("Mod1 Model : Not loaded");
}

const char			*mod1_model::exception_logic_dynamic::what() const noexcept
{
	return ("Mod1 Model : Can't set model as dynamic after loading");
}

void				mod1_model::load(mod1_loader &loader)
{
	is_loaded = true;
	loader.load(data, is_dynamic);
	vertex_number_internal = data.index_buffer.size() * 3;
}

void				mod1_model::use()
{
	if (!is_built)
		throw (exception_not_built());
	if (!is_loaded)
		throw (exception_not_loaded());
	mod1_loader::vao_bind(data.vao);
}

int 				mod1_model::vertex_number()
{
	return (vertex_number_internal);
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
		throw (exception_logic_dynamic());
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