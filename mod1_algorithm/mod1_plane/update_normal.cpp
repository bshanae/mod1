#include "mod1_plane.h"

static glm::vec3		helper_ptr_to_vec3(void *ptr)
{
	auto				*ptr_f = (float *)ptr;

	return (glm::vec3(ptr_f[0], ptr_f[1], ptr_f[2]));
}

static void				helper_vec3_to_ptr(const glm::vec3 &source, float *destination)
{
	for (int i = 0; i < 2; i++)
		destination[i] = source[i];
}

void					mod1_plane::update_normal()
{
	float 				*normal_ptr = data.normal_buffer.data();
	glm::vec3			normal_temp;

	mod1_point2<int>	iter;

	glm::vec3			top_left;
	glm::vec3			top_right;
	glm::vec3			bottom_left;
	glm::vec3			bottom_right;

	for (iter.y = 0; iter.y < size.y - 1; iter.y++)
		for (iter.x = 0; iter.x < size.x - 1; iter.x++)
		{
			top_left = helper_ptr_to_vec3(get_ptr(mod1_point2<int>(iter.x, iter.y), mod1_model_data::slot_point));
			top_right = helper_ptr_to_vec3(get_ptr(mod1_point2<int>(iter.x + 1, iter.y), mod1_model_data::slot_point));
			bottom_left = helper_ptr_to_vec3(get_ptr(mod1_point2<int>(iter.x, iter.y + 1), mod1_model_data::slot_point));
			bottom_right = helper_ptr_to_vec3(get_ptr(mod1_point2<int>(iter.x + 1, iter.y + 1), mod1_model_data::slot_point));

			normal_temp = glm::cross(bottom_left - top_left, top_right - top_left);
			normal_temp = glm::normalize(normal_temp);
			helper_vec3_to_ptr(normal_temp, normal_ptr);
			normal_ptr += 3;

//			normal_temp = glm::cross(bottom_left - bottom_right, top_right - bottom_right);
//			normal_temp = glm::normalize(normal_temp);
			helper_vec3_to_ptr(normal_temp, normal_ptr);
			normal_ptr += 3;
		}
}