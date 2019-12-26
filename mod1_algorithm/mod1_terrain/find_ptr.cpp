#include "mod1_terrain.h"

mod1_point2<int>		mod1_terrain::find_ptr(const mod1_point3<int> &object) const
{
	mod1_point2<int>	iter;
	float 				*ptr;

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			if ((int)ptr[0] == object.x && (int)ptr[2] == object.y)
				return (iter);
		}
	global_error->raise_error("Map : Point (%d, %d) not found", object.x, object.y);
	return (iter);
}