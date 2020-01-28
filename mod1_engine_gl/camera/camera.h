#pragma once

#include "mod1_engine_gl/namespace.h"

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

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_axis, "Mod1 Engine GL, Camera : Unknown axis")

	camera(
						int screen_width,
						int screen_height,
						const glm::vec3 &position = glm::vec3(0, 0, 0));
						~camera() = default;

	void				move(axis axis, sign sign);
	void				move(glm::vec3 &target, axis axis, sign sign);
	void				rotate(axis axis, sign sign);
	void				rotate(glm::vec3 &target, axis axis, sign sign);

private :

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

MOD1_GENERATE_INTERNAL_WITH_VALUE(glm::mat4, projection, glm::mat4(1))
MOD1_GENERATE_INTERNAL_WITH_VALUE(glm::mat4, rotation, glm::mat4(1))
MOD1_GENERATE_INTERNAL_WITH_VALUE(glm::mat4, view, glm::mat4(1))

	glm::vec3			position = glm::vec3();

	const float			movement_speed = MOD1_CAMERA_MOVEMENT_SPEED;
	const float			rotation_speed = MOD1_CAMERA_ROTATION_SPEED;

	void 				update_transformation();

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(projection)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(rotation)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(view)

};


