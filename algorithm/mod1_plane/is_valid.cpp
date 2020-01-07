#include "mod1_plane.h"

bool				mod1_plane::is_valid(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot) const
{
	int 			index;

	try
	{
		index = get_index(iter);
	}
	catch (const exception_coordinate &exception)
	{
		return (false);
	}
	return (data.is_valid(index, slot));
}