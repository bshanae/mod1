#include "camera.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(camera, exception_axis)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(camera, projection)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(camera, rotation)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(camera, view)

					camera::camera(int screen_width, int screen_height, const glm::vec3 &position) :
					MOD1_INTERNAL(projection)(glm::perspective(
						glm::radians(45.0f),
						(float)screen_width / (float)screen_height,
						0.5f,
						10000.0f))
{
	this->position = position;
	MOD1_INTERNAL(view) = glm::mat4(1.0f);
	update_transformation();
}

void				camera::move(axis axis, sign sign)
{
	if (axis == axis::x)
		position += axis_x * movement_speed * (float)sign;
	else if (axis == axis::y)
		position += axis_y * movement_speed * (float)sign;
	else if (axis == axis::z)
		position += axis_z * movement_speed * (float)sign;
	else
		throw (exception_axis());
	update_transformation();
}

void				camera::move(glm::vec3 &target, axis axis, sign sign)
{
	if (axis == axis::x)
		target += axis_x * movement_speed * (float)sign;
	else if (axis == axis::y)
		target += axis_y * movement_speed * (float)sign;
	else if (axis == axis::z)
		target += axis_z * movement_speed * (float)sign;
	else
		throw (exception_axis());
	update_transformation();
}

void				camera::rotate(axis axis, sign sign)
{
	if (axis == axis::x)
		angle_x += (float)sign * rotation_speed;
	else if (axis == axis::y)
		angle_y += (float)sign * rotation_speed;
	else if (axis == axis::z)
		angle_z += (float)sign * rotation_speed;
	else
		throw (exception_axis());
	MOD1_INTERNAL(rotation) = glm::eulerAngleYXZ(angle_y, angle_x, angle_z);
	axis_x = glm::vec3(MOD1_INTERNAL(rotation) * glm::vec4(axis_x_const, 1));
	axis_y = glm::vec3(MOD1_INTERNAL(rotation) * glm::vec4(axis_y_const, 1));
	axis_z = glm::vec3(MOD1_INTERNAL(rotation) * glm::vec4(axis_z_const, 1));
	update_transformation();
}

void				camera::rotate(glm::vec3 &target, axis axis, sign sign)
{
	glm::mat4		rotation_matrix(1);
	glm::vec3		rotation_axis;

	switch (axis)
	{
		case axis::x :
			rotation_axis = axis_x;
			break ;

		case axis::y :
			rotation_axis = axis_y;
			break ;

		case axis::z :
			rotation_axis = axis_z;
			break ;
	}
	rotation_matrix = glm::rotate(rotation_matrix,
		(float)sign * rotation_speed, rotation_axis);
	target = glm::vec3(rotation_matrix * glm::vec4(target, 1));
}

void 				camera::update_transformation()
{
	glm::vec3		direction;
	glm::vec3		up;

	direction = glm::vec3(MOD1_INTERNAL(rotation) * forward_const);
	up = glm::vec3(MOD1_INTERNAL(rotation) * up_const);
	MOD1_INTERNAL(view) = glm::lookAt(position, position + direction, up);
}