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

	buffer_point.allocate(MOD1_PLANE_POINT_SIZE * MOD1_PLANE_NUMBER_OF_POINTS(MOD1_INTERNAL(size)));

	for (iter.y = 0; iter.y < MOD1_INTERNAL(size).y; iter.y++)
		for (iter.x = 0; iter.x < MOD1_INTERNAL(size).x; iter.x++)
		{
			temp = point3<float>(MOD1_INTERNAL(min).x + MOD1_INTERNAL(delta) * iter.x, MOD1_INTERNAL(min).y + MOD1_INTERNAL(delta) * iter.y);
			ptr = (float *) pointer(iter, model_slot::point, index_convention::dual_first);
			temp.write_to_ptr(ptr, point3<float>::convention_xzy);
			if (is_dual(iter))
			{
				ptr = (float *) pointer(iter, model_slot::point, index_convention::dual_second);
				temp.write_to_ptr(ptr, point3<float>::convention_xzy);
			}
		}

	//					Indices

	buffer_index.allocate(MOD1_PLANE_INDEX_SIZE * MOD1_PLANE_NUMBER_OF_TRIANGLES(MOD1_INTERNAL(size)));
	buffer_index.set(0);

	int 				*index_ptr = buffer_index.data();
	int					index_i = 0;

	int					top_left;
	int					top_right;
	int					bottom_left;
	int					bottom_right;

	index_i = 0;
	for (iter.y = 0; iter.y < MOD1_INTERNAL(size).y - 1; iter.y++)
		for (iter.x = 0; iter.x < MOD1_INTERNAL(size).x - 1; iter.x++)
		{
			top_left = index(point2<int>(iter.x, iter.y),
							 is_dual(iter) ? index_convention::dual_second : index_convention::dual_first);
			top_right = index(point2<int>(iter.x + 1, iter.y), index_convention::dual_first);
			bottom_left = index(point2<int>(iter.x, iter.y + 1));
			bottom_right = index(point2<int>(iter.x + 1, iter.y + 1));

			index_ptr[index_i++] = top_left;
			index_ptr[index_i++] = bottom_left;
			index_ptr[index_i++] = top_right;

			index_ptr[index_i++] = top_right;
			index_ptr[index_i++] = bottom_left;
			index_ptr[index_i++] = bottom_right;
		}

	//					Normals

	buffer_normal.allocate(MOD1_PLANE_NORMAL_SIZE * MOD1_PLANE_NUMBER_OF_TRIANGLES(MOD1_INTERNAL(size)));

	temp = point3<float>(0, 0, -1);

	for (iter.y = 0; iter.y < MOD1_INTERNAL(size).y - 1; iter.y++)
		for (iter.x = 0; iter.x < MOD1_INTERNAL(size).x; iter.x++)
		{
			ptr = (float *) pointer(iter, model_slot::normal, index_convention::dual_first);
			temp.write_to_ptr(ptr, point3<float>::convention_xzy);
			if (is_dual(iter))
			{
				ptr = (float *) pointer(iter, model_slot::normal, index_convention::dual_second);
				temp.write_to_ptr(ptr, point3<float>::convention_xzy);
			}
		}

	//					Cut style

	cut_style_data.allocate(MOD1_INTERNAL(size).x - 1, MOD1_INTERNAL(size).y - 1);
	cut_style_data.set(cut_style::upwards);

	//					Colors

	buffer_color.allocate(MOD1_PLANE_COLOR_SIZE * MOD1_PLANE_NUMBER_OF_TRIANGLES(MOD1_INTERNAL(size)));

	temp = point3<float>(0, 0, 1);

	for (iter.y = 0; iter.y < MOD1_INTERNAL(size).y - 1; iter.y++)
		for (iter.x = 0; iter.x < MOD1_INTERNAL(size).x; iter.x++)
			write_color(iter, temp);

	set_as_built();
}