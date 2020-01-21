#include "plane.h"

using namespace		mod1_algorithm;

int 				plane::get_index(
					const point2<int> &iter,
					const index_convention &convention) const
{
	switch (convention)
	{
		case index_convention::single :
		{
			if (iter.x < 0 || iter.x >= MOD1_PLANE_REAL_SIZE_X(size_internal.x))
				throw (exception_coordinate());
			if (iter.y < 0 || iter.y >= size_internal.y)
				throw (exception_coordinate());
			return (iter.y * MOD1_PLANE_REAL_SIZE_X(size_internal.x) + iter.x);
		}
		case index_convention::dual_first :
		{
			if (iter.x < 0 || iter.x >= size_internal.x)
				throw (exception_coordinate());
			if (iter.y < 0 || iter.y >= size_internal.y)
				throw (exception_coordinate());
			return (iter.y * MOD1_PLANE_REAL_SIZE_X(size_internal.x)
					+ MOD1_PLANE_REAL_INDEX_X(iter.x));
		}
		case index_convention::dual_second :
		{
			if (iter.x < 0 || iter.x >= size_internal.x)
				throw (exception_coordinate());
			if (iter.y < 0 || iter.y >= size_internal.y)
				throw (exception_coordinate());
			return (iter.y * MOD1_PLANE_REAL_SIZE_X(size_internal.x)
					+ MOD1_PLANE_REAL_INDEX_X(iter.x) + 1);
		}
		default :
			throw (exception_index_convention());
	}
}

void 				*plane::get_ptr(
					const point2<int> &iter,
					const mod1_engine_gl::model_data::slot_type &slot,
					const index_convention &convention)
{
	return (mod1_engine_gl::model::get_ptr(get_index(iter, convention), slot));
}

void const			*plane::get_ptr(
					const point2<int> &iter,
					const mod1_engine_gl::model_data::slot_type &slot,
					const index_convention &convention) const
{
	return (mod1_engine_gl::model::get_ptr(get_index(iter, convention), slot));
}