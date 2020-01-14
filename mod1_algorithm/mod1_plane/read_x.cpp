#include "mod1_plane.h"

mod1_point3<float>	mod1_plane::read_point(const mod1_point2<int> &iter) const
{
	return (mod1_point3<float>(
		(float *)get_ptr(iter, mod1_model_data::slot_point, convention_dual_first),
		mod1_point3<float>::convention_xzy));
}

float				mod1_plane::read_height(const mod1_point2<int> &iter) const
{
	return (((float *)get_ptr(iter, mod1_model_data::slot_point, convention_dual_first))[1]);
}