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

	printf("[%d, %d] : normal = (%f, %f, %f)\n",
		iter.x, iter.y,
		normal.x, normal.z, normal.y);

	ptr = (float *)get_ptr(iter_local, mod1_model_data::slot_normal);
	for (int i = 0; i < 2; i++)
		ptr[i] = normal[i];
}

void					mod1_plane::update_normal()
{
	mod1_point2<int>	iter;

	for (iter.y = 1; iter.y < size.y - 1; iter.y++)
		for (iter.x = 1; iter.x < size.x - 1; iter.x++)
			update_normal_helper(iter);
}