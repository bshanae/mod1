#include "mod1_model.h"

					mod1_model::mod1_model()
{
	vao = -1;
	vertex_number_internal = -1;
}

void				mod1_model::load(mod1_loader &loader)
{
	loader.load(data, vao);
	vertex_number_internal = data.index_buffer.size() * 3;
}

void				mod1_model::use()
{
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