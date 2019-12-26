#include "mod1_model.h"

					mod1_model::mod1_model()
{
	vao = -1;
	vertex_number_internal = -1;
}

void				mod1_model::load(mod1_loader &loader)
{
	is_loaded = true;
	loader.load(data, vao);
	vertex_number_internal = data.index_buffer.size() * 3;
}

const char			*mod1_model::exception_not_built::what() const noexcept
{
	return ("Mod1 Model : Not built");
}

const char			*mod1_model::exception_not_loaded::what() const noexcept
{
	return ("Mod1 Model : Not loaded");
}

void				mod1_model::use()
{
	if (!is_built)
		throw (exception_not_built());
	if (!is_loaded)
		throw (exception_not_loaded());
	mod1_loader::vao_bind(vao);
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