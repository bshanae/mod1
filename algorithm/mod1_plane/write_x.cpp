#include "mod1_plane.h"

bool				mod1_plane::write_height(const mod1_point2<int> &iter, const float &z)
{
	float 			*ptr;

	ptr = (float *)get_ptr(iter, mod1_model_data::slot_point, convention_dual_first);
	ptr[1] = z;

	if (is_dual(iter))
	{
		ptr = (float *) get_ptr(iter, mod1_model_data::slot_point, convention_dual_second);
		ptr[1] = z;
		return (true);
	}

	return (false);
}