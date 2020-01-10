#include "mod1_plane.h"

bool				mod1_plane::is_valid(
					const mod1_point2<int> &iter,
					const mod1_model_data::slot_type &slot,
					const mod1_indexing_convention &convention) const
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

bool 				mod1_plane::is_dual(const mod1_point2<int> &iter) const
{
	return (iter.x > 0 && iter.x < size.x - 1 && iter.y < size.y - 1);
}