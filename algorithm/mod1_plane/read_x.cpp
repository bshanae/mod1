#include "mod1_plane.h"

point3<float>	mod1_plane::read_point(const point2<int> &iter) const
{
	return (point3<float>(
		(float *)get_ptr(iter, model_data::slot_point, convention_dual_first),
		point3<float>::convention_xzy));
}

float				mod1_plane::read_height(const point2<int> &iter) const
{
	return (((float *)get_ptr(iter, model_data::slot_point, convention_dual_first))[1]);
}