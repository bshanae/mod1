#include "camera.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(camera, projection_type)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(camera, position)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(camera, rotation)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(camera, view)

//					PUBLIC

					camera::camera(int screen_width, int screen_height, const glm::vec3 &position) :
					screen_width((float)screen_width),
					screen_height((float)screen_height)
{
	update_perspective_projection();
	update_orthographic_projection();

	this->MOD1_INTERNAL(position) = position;
	MOD1_INTERNAL(view) = glm::mat4(1.0f);
	update_transformation();
}

void				camera::set_zoom(const float &zoom)
{
	orthographic_zoom = zoom;
	update_orthographic_projection();
}

void				camera::set_position(const glm::vec3 &position)
{
	MOD1_INTERNAL(position) = position;
	update_transformation();
}

void				camera::set_direction(const glm::vec3 &direction)
{
	angle_x = direction.x;
	angle_y = direction.y;
	angle_z = direction.z;

	MOD1_INTERNAL(rotation) = glm::eulerAngleYXZ(angle_y, angle_x, angle_z);
	axis_x = glm::vec3(MOD1_INTERNAL(rotation) * glm::vec4(axis_x_const, 1.f));
	axis_y = glm::vec3(MOD1_INTERNAL(rotation) * glm::vec4(axis_y_const, 1.f));
	axis_z = glm::vec3(MOD1_INTERNAL(rotation) * glm::vec4(axis_z_const, 1.f));

	update_transformation();
}

void				camera::move(axis axis, sign sign)
{
	if (axis == axis::x)
		MOD1_INTERNAL(position) += axis_x * movement_speed * (float)sign;
	else if (axis == axis::y)
		MOD1_INTERNAL(position) += axis_y * movement_speed * (float)sign;
	else if (axis == axis::z)
		switch (MOD1_INTERNAL(projection_type))
		{
			case projection_type::perspective :
				MOD1_INTERNAL(position) += axis_z * movement_speed * (float)sign;
				break;
			case projection_type::orthographic :
				orthographic_zoom -= orthographic_zoom_speed * (float)sign;
				update_orthographic_projection();
				break;
		}
	else
		throw (exception_enum());
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
		throw (exception_enum());
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
		throw (exception_enum());

	MOD1_INTERNAL(rotation) = glm::eulerAngleYXZ(angle_y, angle_x, angle_z);
	axis_x = glm::vec3(MOD1_INTERNAL(rotation) * glm::vec4(axis_x_const, 1.f));
	axis_y = glm::vec3(MOD1_INTERNAL(rotation) * glm::vec4(axis_y_const, 1.f));
	axis_z = glm::vec3(MOD1_INTERNAL(rotation) * glm::vec4(axis_z_const, 1.f));

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

		default :
			throw (exception_enum());
	}

	rotation_matrix = glm::rotate(rotation_matrix,
		(float)sign * rotation_speed, rotation_axis);
	target = glm::vec3(rotation_matrix * glm::vec4(target, 1));
}

const glm::mat4		&camera::projection()
{
	switch (MOD1_INTERNAL(projection_type))
	{
		case projection_type::perspective :
			return (projection_perspective);
		case projection_type::orthographic :
			return (projection_orthographic);
		default :
			throw (exception_enum());
	}
}

void				camera::switch_projection()
{
	switch (MOD1_INTERNAL(projection_type))
	{
		case projection_type::perspective :
			MOD1_INTERNAL(projection_type) = projection_type::orthographic;
			break;
		case projection_type::orthographic :
			MOD1_INTERNAL(projection_type) = projection_type::perspective;
			break;
		default :
			throw (exception_enum());
	}
}

//					PRIVATE

void 				camera::update_transformation()
{
	glm::vec3		direction;
	glm::vec3		up;

	direction = glm::vec3(MOD1_INTERNAL(rotation) * forward_const);
	up = glm::vec3(MOD1_INTERNAL(rotation) * up_const);
	MOD1_INTERNAL(view) = glm::lookAt(MOD1_INTERNAL(position), MOD1_INTERNAL(position) + direction, up);
}

void				camera::update_perspective_projection()
{
	projection_perspective = glm::perspective(
		glm::radians(45.0f), this->screen_width / this->screen_height,
		MOD1_CAMERA_NEAR_PLANE, MOD1_CAMERA_FAR_PLANE);
}

void 				camera::update_orthographic_projection()
{
	projection_orthographic = glm::ortho(
		this->screen_width * -1.f / orthographic_zoom, this->screen_width / orthographic_zoom,
		this->screen_height * -1.f / orthographic_zoom, this->screen_height / orthographic_zoom,
		MOD1_CAMERA_NEAR_PLANE, MOD1_CAMERA_FAR_PLANE);
}