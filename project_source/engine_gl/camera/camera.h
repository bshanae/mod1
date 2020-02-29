#pragma once

#include "engine_gl/namespace.h"

enum class				mod1_engine_gl::axis
{
	x,
	y,
	z
};

enum class				mod1_engine_gl::sign : int
{
	negative = -1,
	positive = 1
};

class					mod1_engine_gl::camera
{
public :

						camera(
						int screen_width,
						int screen_height,
						const glm::vec3 &position = glm::vec3(0, 0, 0));
						~camera() = default;

	void				set_zoom(const float &zoom);
	void				set_position(const glm::vec3 &position);
	void				set_direction(const glm::vec3 &direction);

	void				move(axis axis, sign sign);
	void				move(glm::vec3 &target, axis axis, sign sign);
	void				rotate(axis axis, sign sign);
	void				rotate(glm::vec3 &target, axis axis, sign sign);

	enum class			projection_type
	{
		perspective,
		orthographic
	};

	void				switch_projection();
	const glm::mat4		&projection();

private :

	const float			screen_width;
	const float			screen_height;

	const glm::vec3		axis_x_const = glm::vec3(1, 0, 0);
	const glm::vec3		axis_z_const = glm::vec3(0, 0, 1);
	const glm::vec3		axis_y_const = glm::vec3(0, 1, 0);
	const glm::vec4		up_const = glm::vec4(0, 1, 0, 1);
	const glm::vec4		forward_const = glm::vec4(0, 0, -1, 1);

	float				angle_x = 0;
	float				angle_y = 0;
	float				angle_z = 0;

	glm::vec3			axis_x = glm::vec3(1, 0, 0);
	glm::vec3			axis_z = glm::vec3(0, 0, 1);
	glm::vec3			axis_y = glm::vec3(0, 1, 0);

MOD1_GENERATE_INTERNAL_WITH_VALUE(enum projection_type, projection_type, projection_type::perspective)

	glm::mat4			projection_perspective = glm::mat4(1);
	glm::mat4			projection_orthographic = glm::mat4(1);

MOD1_GENERATE_INTERNAL_WITH_VALUE(glm::mat4, rotation, glm::mat4(1))
MOD1_GENERATE_INTERNAL_WITH_VALUE(glm::mat4, view, glm::mat4(1))

MOD1_GENERATE_INTERNAL_WITH_VALUE(glm::vec3, position, glm::vec3())

	const float			movement_speed = MOD1_CAMERA_MOVEMENT_SPEED;
	const float			rotation_speed = MOD1_CAMERA_ROTATION_SPEED;

	float				orthographic_zoom = 1;
	const float			orthographic_zoom_speed = MOD1_CAMERA_ZOOM_SPEED;

	void 				update_transformation();
	void				update_perspective_projection();
	void				update_orthographic_projection();

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(projection_type)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(position)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(rotation)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(view)
};


