#include "plane.h"

using namespace		mod1_algorithm;

void 				*plane::pointer(
					const point2<int> &iter,
					const model_slot &slot,
					const index_convention &convention)
{
	return (mod1_engine_gl::model::pointer(index(iter, convention), slot));
}

void const			*plane::pointer(
					const point2<int> &iter,
					const model_slot &slot,
					const index_convention &convention) const
{
	return (mod1_engine_gl::model::pointer(index(iter, convention), slot));
}