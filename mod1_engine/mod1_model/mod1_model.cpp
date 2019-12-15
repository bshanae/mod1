#include "mod1_model.h"

					mod1_model::mod1_model()
{
	vao = -1;
	eab = -1;
	vertex_number_value = -1;
}

void				mod1_model::load(mod1_loader &loader)
{
	loader.load(data, vao, eab);
}

void				mod1_model::use()
{
	mod1_loader::vao_bind(vao);
}

int 				mod1_model::vertex_number()
{
	return (vertex_number_value);
}