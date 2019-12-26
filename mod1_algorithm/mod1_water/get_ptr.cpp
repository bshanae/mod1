#include "mod1_water.h"

void				*mod1_water::get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot)
{
	return (mod1_model::get_ptr(terrain.model_get_index(iter), slot));
}