#include "mod1_camera.h"

					mod1_camera::mod1_camera(int screen_width, int screen_height, const glm::vec3 &position)
{
	this->position = position;
	matrix_view = glm::mat4(1.0f);
	matrix_projection = glm::perspective(
		glm::radians(45.0f),
		(float)screen_width / (float)screen_height,
		0.1f,
		100000.0f);
	update_transformation();
}

const glm::mat4		&mod1_camera::transformation()
{
	return (transformation_internal);
}

void				mod1_camera::move(mod1_axis axis, mod1_sign sign)
{
	if (axis == mod1_axis_x)
		position += axis_x * movement_speed * (float)sign;
	else if (axis == mod1_axis_y)
		position += axis_y * movement_speed * (float)sign;
	else if (axis == mod1_axis_z)
		position += axis_z * movement_speed * (float)sign;
	else
		global_error->raise_warning("Camera : Unknown axis");
	update_transformation();
}

void				mod1_camera::rotate(mod1_axis axis, mod1_sign sign)
{
	if (axis == mod1_axis_x)
		angle_x += (float)sign * rotation_speed;
	else if (axis == mod1_axis_y)
		angle_y += (float)sign * rotation_speed;
	else if (axis == mod1_axis_z)
		angle_z += (float)sign * rotation_speed;
	else
		global_error->raise_warning("Camera : Unknown axis");
	matrix_rotation = glm::eulerAngleYXZ(angle_y, angle_x, angle_z);
	axis_x = glm::vec3(matrix_rotation * glm::vec4(axis_x_const, 1));
	axis_y = glm::vec3(matrix_rotation * glm::vec4(axis_y_const, 1));
	axis_z = glm::vec3(matrix_rotation * glm::vec4(axis_z_const, 1));
	update_transformation();
}

void 				mod1_camera::update_transformation()
{
	glm::vec3		direction;
	glm::vec3		up;

	direction = glm::vec3(matrix_rotation * forward_const);
	up = glm::vec3(matrix_rotation * up_const);
	matrix_view = glm::lookAt(position, position + direction, up);
	transformation_internal = matrix_projection * matrix_view;
}