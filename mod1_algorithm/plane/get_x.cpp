#include "plane.h"

using namespace		mod1_algorithm;

int 				plane::get_index(
					const point2<int> &iter,
					const mod1_indexing_convention &convention) const
{
	switch (convention)
	{
		case convention_single :
		{
			if (iter.x < 0 || iter.x >= MOD1_PLANE_REAL_SIZE_X(size_internal.x))
				throw (exception_coordinate());
			if (iter.y < 0 || iter.y >= size_internal.y)
				throw (exception_coordinate());
			return (iter.y * MOD1_PLANE_REAL_SIZE_X(size_internal.x) + iter.x);
		}
		case convention_dual_first :
		{
			if (iter.x < 0 || iter.x >= size_internal.x)
				throw (exception_coordinate());
			if (iter.y < 0 || iter.y >= size_internal.y)
				throw (exception_coordinate());
			return (iter.y * MOD1_PLANE_REAL_SIZE_X(size_internal.x)
					+ MOD1_PLANE_REAL_INDEX_X(iter.x));
		}
		case convention_dual_second :
		{
			if (iter.x < 0 || iter.x >= size_internal.x)
				throw (exception_coordinate());
			if (iter.y < 0 || iter.y >= size_internal.y)
				throw (exception_coordinate());
			return (iter.y * MOD1_PLANE_REAL_SIZE_X(size_internal.x)
					+ MOD1_PLANE_REAL_INDEX_X(iter.x) + 1);
		}
		default :
			throw (exception_indexing_convention());
	}
}

void 				*plane::get_ptr(
					const point2<int> &iter,
					const mod1_engine::model_data::slot_type &slot,
					const mod1_indexing_convention &convention)
{
	return (model::get_ptr(get_index(iter, convention), slot));
}


const void 			*plane::get_ptr(
					const point2<int> &iter,
					const mod1_engine::model_data::slot_type &slot,
					const mod1_indexing_convention &convention) const
{
	return (model::get_ptr(get_index(iter, convention), slot));
}