#include "mod1_map.h"

bool					mod1_map::model_write_height(const mod1_point2<int> &iter, const float &height)
{
	float				*ptr;

	try
	{
		ptr = model_get_ptr(iter, mod1_map::mod1_map_slot_point) + 1;
		if (*ptr < height)
			*ptr = height;
		return (true);
	}
	catch (mod1_map::exception_bad_coordinate &exception)
	{
		return (false);
	}
}