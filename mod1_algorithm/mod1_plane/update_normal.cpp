#include "mod1_plane.h"

void 					mod1_plane::update_normal_helper(const mod1_point2<int> &iter)
{
	float 				height[4];
	mod1_point2<int>	iter_local;
	glm::vec3			normal;
	float				*ptr;

	iter_local = mod1_point2<int>(iter.x - 1, iter.y + 0);
	height[0] = ((float *)get_ptr(iter_local, mod1_model_data::slot_point))[1];

	iter_local = mod1_point2<int>(iter.x + 1, iter.y + 0);
	height[1] = ((float *)get_ptr(iter_local, mod1_model_data::slot_point))[1];

	iter_local = mod1_point2<int>(iter.x + 0, iter.y - 1);
	height[2] = ((float *)get_ptr(iter_local, mod1_model_data::slot_point))[1];

	iter_local = mod1_point2<int>(iter.x + 0, iter.y + 1);
	height[3] = ((float *)get_ptr(iter_local, mod1_model_data::slot_point))[1];

	normal = glm::vec3(height[0] - height[1], 2, height[2] - height[3]);
	normal = glm::normalize(normal);

	ptr = (float *)get_ptr(iter_local, mod1_model_data::slot_normal);
	for (int i = 0; i < 2; i++)
		ptr[i] = normal[i];
}

void	 				mod1_plane::update_normal_helper_test(
						const mod1_point2<int> &a,
						const mod1_point2<int> &b,
						const mod1_point2<int> &c)
{
	float 				*ptr_a;
	float 				*ptr_b;
	float 				*ptr_c;
	glm::vec3 			x;
	glm::vec3 			y;
	glm::vec3			normal;

	ptr_a = (float *)get_ptr(a, mod1_model_data::slot_point);
	ptr_b = (float *)get_ptr(b, mod1_model_data::slot_point);
	ptr_c = (float *)get_ptr(c, mod1_model_data::slot_point);

	for (int i = 0; i < 3; i++)
	{
		x[i] = ptr_b[i] - ptr_a[i];
		y[i] = ptr_c[i] - ptr_a[i];
	}

	normal = glm::normalize(glm::cross(x, y));

	ptr_a = (float *)get_ptr(a, mod1_model_data::slot_normal);
	for (int i = 0; i < 3; i++)
		ptr_a[i] = normal[i];
}

void					mod1_plane::update_normal()
{
#define SOLUTION_A

#ifdef SOLUTION_A
	mod1_point2<int>	iter;

	for (iter.y = 1; iter.y < size.y - 1; iter.y++)
		for (iter.x = 1; iter.x < size.x - 1; iter.x++)
			update_normal_helper(iter);
#endif

#ifdef SOLUTION_B
	mod1_point2<int>	iter;

	mod1_point2<int>	top_left;
	mod1_point2<int>	top_right;
	mod1_point2<int>	bottom_left;
	mod1_point2<int>	bottom_right;

	for (iter.y = 0; iter.y < size.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size.x - 1; iter.x++)
		{
			top_left = mod1_point2<int>(iter.x, iter.y);
			top_right = mod1_point2<int>(iter.x + 1, iter.y);
			bottom_left = mod1_point2<int>(iter.x, iter.y + 1);
			bottom_right = mod1_point2<int>(iter.x + 1, iter.y + 1);

			update_normal_helper_test(top_left, bottom_left, top_right);
			update_normal_helper_test(top_right, bottom_left, bottom_right);
		}
#endif
}