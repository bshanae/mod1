#include "mod1_terrain.h"

bool					mod1_terrain::model_write_height(const mod1_point2<int> &iter, const float &height)
{
	float				*ptr;

	try
	{
		ptr = (float *)model_get_ptr(iter, mod1_model_data::slot_point) + 1;
		if (*ptr < height)
			*ptr = height;
		return (true);
	}
	catch (mod1_terrain::exception_bad_coordinate &exception)
	{
		return (false);
	}
}