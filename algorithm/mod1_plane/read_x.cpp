#include "mod1_plane.h"

float				mod1_plane::read_height(const mod1_point2<int> &iter)
{
	return (((float *)get_ptr(iter, mod1_model_data::slot_point, convention_dual_first))[1]);
}