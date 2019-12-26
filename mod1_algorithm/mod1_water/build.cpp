#include "mod1_water.h"

void 					mod1_water::build()
{
	set(terrain->min, terrain->max, terrain->delta);
	mod1_plane::build();

	mod1_point2<int>	iter;
	float				*ptr;

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			ptr[1] = -10;
		}

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_color);
			ptr[0] = 0;
			ptr[1] = 0;
			ptr[2] = 1;
		}
}