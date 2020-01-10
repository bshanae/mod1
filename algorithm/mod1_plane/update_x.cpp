#include "mod1_plane.h"

void	 				mod1_plane::update_normal_helper(
						const int &a,
						const int &b,
						const int &c,
						const int &n)
{
	float 				*ptr_a;
	float 				*ptr_b;
	float 				*ptr_c;
	glm::vec3 			x;
	glm::vec3 			y;
	glm::vec3			normal;

	ptr_a = (float *)mod1_model::get_ptr(a, mod1_model_data::slot_point);
	ptr_b = (float *)mod1_model::get_ptr(b, mod1_model_data::slot_point);
	ptr_c = (float *)mod1_model::get_ptr(c, mod1_model_data::slot_point);

	for (int i = 0; i < 3; i++)
	{
		x[i] = ptr_b[i] - ptr_a[i];
		y[i] = ptr_c[i] - ptr_a[i];
	}

	normal = glm::normalize(glm::cross(x, y));

	ptr_a = (float *)mod1_model::get_ptr(n, mod1_model_data::slot_normal);
	for (int i = 0; i < 3; i++)
		ptr_a[i] = normal[i];
}

void					mod1_plane::update_normal()
{
	mod1_point2<int>	iter;

	int 				normal[2];

	int					top_left;
	int					top_right;
	int					bottom_left;
	int					bottom_right;

	return ;

	for (iter.y = 0; iter.y < size.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size.x - 1; iter.x++)
		{
			normal[0] = get_index(mod1_point2<int>(iter.x, iter.y), convention_single);
			normal[1] = get_index(mod1_point2<int>(iter.x + 1, iter.y), convention_single);

			top_left = get_index(mod1_point2<int>(iter.x, iter.y),
				is_dual(iter) ? convention_dual_second : convention_dual_first);
			top_right = get_index(mod1_point2<int>(iter.x + 1, iter.y),
				is_dual(iter) ? convention_dual_first : convention_dual_second);
			bottom_left = get_index(mod1_point2<int>(iter.x, iter.y + 1));
			bottom_right = get_index(mod1_point2<int>(iter.x + 1, iter.y + 1));

			update_normal_helper(top_left, bottom_left, top_right, normal[0]);
			update_normal_helper(top_right, bottom_left, bottom_right, normal[1]);
		}
}

void 					mod1_plane::update_final()
{
	mod1_point2<int>	iter;
	float				*ptr;
	mod1_point3<float>	point;


	final_min = mod1_point3<float>(std::numeric_limits<float>::max());
	final_max = mod1_point3<float>(std::numeric_limits<float>::min());
	for (iter.y = 0; iter.y < size.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size.x - 1; iter.x++)
		{
			ptr = (float *)get_ptr(iter, mod1_model_data::slot_point);
			point = mod1_point3<float>(ptr[0], ptr[2], ptr[1]);
			final_min = mod1_point3<float>::min(final_min, point);
			final_max = mod1_point3<float>::max(final_max, point);
		}
}