#include "plane.h"

using namespace		mod1_algorithm;

point3<float>		plane::read_point(const point2<int> &iter) const
{

	return (point3<float>(
		(float *)get_ptr(iter, model_slot::point, index_convention::dual_first),
		point3<float>::convention_xzy));
}

float				plane::read_height(const point2<int> &iter) const
{
	return (((float *)get_ptr(iter, model_slot::point, index_convention::dual_first))[1]);
}