#include "mod1_plane.h"

void	 				mod1_plane::update_normal_helper(
						const int &index_a,
						const int &index_b,
						const int &index_c)
{
	float 				*ptr_a;
	float 				*ptr_b;
	float 				*ptr_c;
	float 				*ptr_n;

	mod1_point3<float>	a;
	mod1_point3<float>	b;
	mod1_point3<float>	c;

	mod1_point3<float>	normal;

	ptr_a = (float *)mod1_model::get_ptr(index_a, mod1_model_data::slot_point);
	ptr_b = (float *)mod1_model::get_ptr(index_b, mod1_model_data::slot_point);
	ptr_c = (float *)mod1_model::get_ptr(index_c, mod1_model_data::slot_point);


	a = mod1_point3<float>(ptr_a, mod1_point3<float>::convention_xzy);
	b = mod1_point3<float>(ptr_b, mod1_point3<float>::convention_xzy);
	c = mod1_point3<float>(ptr_c, mod1_point3<float>::convention_xzy);

	normal = mod1_point3<float>::cross(c - a, b - a).normalized();

	ptr_n = (float *)mod1_model::get_ptr(index_a, mod1_model_data::slot_normal);
	normal.write_to_ptr(ptr_n, mod1_point3<float>::convention_xzy);
}

void					mod1_plane::update_normal()
{
	mod1_point2<int>	iter;

	int					top_left;
	int					top_right;
	int					bottom_left;
	int					bottom_right;


	for (iter.y = 0; iter.y < size_internal.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size_internal.x - 1; iter.x++)
		{
			top_left = get_index(mod1_point2<int>(iter.x, iter.y),
				is_dual(iter) ? convention_dual_second : convention_dual_first);
			top_right = get_index(mod1_point2<int>(iter.x + 1, iter.y), convention_dual_first);
			bottom_left = get_index(mod1_point2<int>(iter.x, iter.y + 1));
			bottom_right = get_index(mod1_point2<int>(iter.x + 1, iter.y + 1));

			update_normal_helper(top_left, bottom_left, top_right);
			update_normal_helper(top_right, bottom_left, bottom_right);
		}
}

void 					mod1_plane::update_final()
{
	mod1_point2<int>	iter;
	float				*ptr;
	mod1_point3<float>	point;


	final_min_internal = mod1_point3<float>(std::numeric_limits<float>::max());
	final_max_internal = mod1_point3<float>(std::numeric_limits<float>::min());
	for (iter.y = 0; iter.y < size_internal.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size_internal.x - 1; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			point = mod1_point3<float>(ptr[0], ptr[2], ptr[1]);
			final_min_internal = mod1_point3<float>::min(final_min_internal, point);
			final_max_internal = mod1_point3<float>::max(final_max_internal, point);
		}
}