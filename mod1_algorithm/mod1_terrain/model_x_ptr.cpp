#include "mod1_terrain.h"

void					*mod1_terrain::model_get_ptr(const mod1_point2<int> &iter, const mod1_model_data::slot_type &slot) const
{
	return ((void *)get_ptr(model_get_index(iter), slot));
}

mod1_point2<int>		mod1_terrain::model_find_ptr(const mod1_point3<int> &object) const
{
	mod1_point2<int>	iter;
	float 				*ptr;

	for (iter.y = 0; iter.y < model_size.y; iter.y++)
		for (iter.x = 0; iter.x < model_size.x; iter.x++)
		{
			ptr = (float *)model_get_ptr(iter, mod1_model_data::slot_point);
			if ((int)ptr[0] == object.x && (int)ptr[2] == object.y)
				return (iter);
		}
	global_error->raise_error("Map : Point (%d, %d) not found", object.x, object.y);
	return (iter);
}