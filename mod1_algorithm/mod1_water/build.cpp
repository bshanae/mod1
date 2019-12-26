#include "mod1_water.h"

void 					mod1_water::build()
{
	//					Points

	data.point_buffer.allocate(3 * size.x * size.y);

	mod1_point2<int>	iter;
	float				*ptr;

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			ptr[0] = (float)(terrain.model_min.x + terrain.model_delta * iter.x);
			ptr[1] = 0;
			ptr[2] = (float)(terrain.model_min.y + terrain.model_delta * iter.y);
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
			top_left = terrain.model_get_index(mod1_point2<int>(iter.x, iter.y));
			top_right = terrain.model_get_index(mod1_point2<int>(iter.x + 1, iter.y));
			bottom_left = terrain.model_get_index(mod1_point2<int>(iter.x, iter.y + 1));
			bottom_right = terrain.model_get_index(mod1_point2<int>(iter.x + 1, iter.y + 1));

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

	mod1_point3<float>	color;

	data.color_buffer.allocate(6 * (size.x - 1) * (size.y - 1));

	for (iter.y = 0; iter.y < size.y; iter.y++)
		for (iter.x = 0; iter.x < size.x; iter.x++)
		{
			ptr = (float *)model_get_ptr(iter, mod1_model_data::slot_point);
			color = model_get_color(ptr[1]);
			ptr = (float *)model_get_ptr(iter, mod1_model_data::slot_color);
			ptr[0] = color.x;
			ptr[1] = color.y;
			ptr[2] = color.z;
		}


}