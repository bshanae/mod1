#include "plane.h"

using namespace			mod1_algorithm;

void					plane::build()
{
	if (!is_set)
		throw (exception_logic());

	point2<int>			iter;
	float				*ptr;
	point3<float>		temp;

	//					Points

	data.point_buffer.allocate(MOD1_PLANE_POINT_SIZE * MOD1_PLANE_NUMBER_OF_POINTS(size_internal));

	for (iter.y = 0; iter.y < size_internal.y; iter.y++)
		for (iter.x = 0; iter.x < size_internal.x; iter.x++)
		{
			temp = point3<float>(min_internal.x + delta_internal * iter.x, min_internal.y + delta_internal * iter.y);
			ptr = (float *)get_ptr(iter, model_slot::point, index_convention::dual_first);
			temp.write_to_ptr(ptr, point3<float>::convention_xzy);
			if (is_dual(iter))
			{
				ptr = (float *)get_ptr(iter, model_slot::point, index_convention::dual_second);
				temp.write_to_ptr(ptr, point3<float>::convention_xzy);
			}
		}

	//					Indices

	data.index_buffer.allocate(MOD1_PLANE_INDEX_SIZE * MOD1_PLANE_NUMBER_OF_TRIANGLES(size_internal));
	data.index_buffer.set(0);

	int 				*index_ptr = data.index_buffer.data();
	int					index_i = 0;

	int					top_left;
	int					top_right;
	int					bottom_left;
	int					bottom_right;

	index_i = 0;
	for (iter.y = 0; iter.y < size_internal.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size_internal.x - 1; iter.x++)
		{
			top_left = get_index(point2<int>(iter.x, iter.y),
			    is_dual(iter) ? index_convention::dual_second : index_convention::dual_first);
			top_right = get_index(point2<int>(iter.x + 1, iter.y), index_convention::dual_first);
			bottom_left = get_index(point2<int>(iter.x, iter.y + 1));
			bottom_right = get_index(point2<int>(iter.x + 1, iter.y + 1));

			index_ptr[index_i++] = top_left;
			index_ptr[index_i++] = bottom_left;
			index_ptr[index_i++] = top_right;

			index_ptr[index_i++] = top_right;
			index_ptr[index_i++] = bottom_left;
			index_ptr[index_i++] = bottom_right;
		}

	//					Normals

	data.normal_buffer.allocate(MOD1_PLANE_NORMAL_SIZE * MOD1_PLANE_NUMBER_OF_TRIANGLES(size_internal));

	temp = point3<float>(0, 0, -1);

	for (iter.y = 0; iter.y < size_internal.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size_internal.x; iter.x++)
		{
			ptr = (float *)get_ptr(iter, model_slot::normal, index_convention::dual_first);
			temp.write_to_ptr(ptr, point3<float>::convention_xzy);
			if (is_dual(iter))
			{
				ptr = (float *)get_ptr(iter, model_slot::normal, index_convention::dual_second);
				temp.write_to_ptr(ptr, point3<float>::convention_xzy);
			}
		}

	//					Cut style

	cut_style_data.allocate(size_internal.y - 1, size_internal.x - 1);
	cut_style_data.set(cut_style::upwards);

	//					Colors

	data.color_buffer.allocate(MOD1_PLANE_COLOR_SIZE * MOD1_PLANE_NUMBER_OF_TRIANGLES(size_internal));

	temp = point3<float>(0, 0, 1);

	for (iter.y = 0; iter.y < size_internal.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size_internal.x; iter.x++)
		{
			printf("%d %d\n", iter.x, iter.y);
			write_color(iter, temp);
		}

	set_as_built();
}