#include "plane.h"

using namespace		mod1_algorithm;

bool				plane::is_valid(
					const point2<int> &iter,
					const mod1_engine_gl::model_data::slot_type &slot,
					const index_convention &convention) const
{
	int 			index;

	try
	{
		index = get_index(iter, convention);
	}
	catch (const exception_coordinate &exception)
	{
		return (false);
	}
	return (data.is_valid(index, slot));
}

bool 				plane::is_dual(const point2<int> &iter) const
{
	return (iter.x > 0 && iter.x < MOD1_INTERNAL(size).x - 1 && iter.y < MOD1_INTERNAL(size).y - 1);
}