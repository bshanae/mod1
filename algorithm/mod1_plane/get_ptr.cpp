#include "mod1_plane.h"

void 					*mod1_plane::get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot)
{
	return (mod1_model::get_ptr(get_index(iter), slot));
}

void const				*mod1_plane::get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot) const
{
	return (mod1_model::get_ptr(get_index(iter), slot));
}