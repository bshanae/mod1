#include "plane.h"

using namespace		mod1_algorithm;

point3<float>		plane::read_point(const point2<int> &iter) const
{

	return (point3<float>(
		(float *)get_ptr(iter, mod1_engine::model_data::slot_point, convention_dual_first),
		point3<float>::convention_xzy));
}

float				plane::read_height(const point2<int> &iter) const
{
	return (((float *)get_ptr(iter, mod1_engine::model_data::slot_point, convention_dual_first))[1]);
}