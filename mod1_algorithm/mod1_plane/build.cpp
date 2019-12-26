#include "mod1_plane.h"

void					mod1_plane::build()
{
	if (!is_set)
		throw (exception_not_set());

	set_as_built();

	//					Points

	data.point_buffer.allocate(3 * size.x * size.y);

	mod1_point2<int>	iter;
	float				*ptr;

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			ptr[0] = (float)(min.x + delta * iter.x);
			ptr[1] = 0;
			ptr[2] = (float)(min.y + delta * iter.y);
		}

	//					Indices

	data.index_buffer.allocate(6 * (size.x - 1) * (size.y - 1));

	int 				*index_ptr = data.index_buffer.data();
	int					index_i = 0;

	int					top_left;
	int					top_right;
	int					bottom_left;
	int					bottom_right;

	index_i = 0;
	for (iter.y = 0; iter.y < size.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size.x - 1; iter.x++)
		{
			top_left = get_index(mod1_point2<int>(iter.x, iter.y));
			top_right = get_index(mod1_point2<int>(iter.x + 1, iter.y));
			bottom_left = get_index(mod1_point2<int>(iter.x, iter.y + 1));
			bottom_right = get_index(mod1_point2<int>(iter.x + 1, iter.y + 1));

			index_ptr[index_i++] = top_left;
			index_ptr[index_i++] = bottom_left;
			index_ptr[index_i++] = top_right;

			index_ptr[index_i++] = top_right;
			index_ptr[index_i++] = bottom_left;
			index_ptr[index_i++] = bottom_right;
		}

	//					Normals

	data.normal_buffer.allocate(6 * (size.x - 1) * (size.y - 1));

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_normal);
			ptr[0] = 0;
			ptr[1] = 1.;
			ptr[2] = 0;
		}

	//					Colors

	data.color_buffer.allocate(6 * (size.x - 1) * (size.y - 1));

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_color);
			ptr[0] = 1;
			ptr[1] = 0;
			ptr[2] = 0;
		}
}