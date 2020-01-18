#include "plane.h"

using namespace		mod1_algorithm;

bool				plane::write_height(const point2<int> &iter, const float &z)
{
	float 			*ptr;

	ptr = (float *)get_ptr(iter, model_slot::point, convention_dual_first);
	ptr[1] = z;

	if (is_dual(iter))
	{
		ptr = (float *)get_ptr(iter, model_slot::point, convention_dual_second);
		ptr[1] = z;
		return (true);
	}

	return (false);
}

void				plane::write_color(const point2<int> &iter, const point3<float> &color)
{
	float 			*ptr;

	ptr = (float *)get_ptr(iter, model_slot::color, convention_dual_first);
	color.write_to_ptr(ptr, point3<float>::convention_xyz);

	if (is_dual(iter))
	{
		ptr = (float *) get_ptr(iter, model_slot::color, convention_dual_second);
		color.write_to_ptr(ptr, point3<float>::convention_xyz);
	}

}