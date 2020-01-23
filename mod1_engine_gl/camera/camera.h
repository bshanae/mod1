#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_control.h"
#include "mod1_main/mod1_generic.h"

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

						camera(
						int screen_width,
						int screen_height,
						const glm::vec3 &position = glm::vec3(0, 0, 0));
						~camera() = default;

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_axis, "Mod1 Engine GL, Camera : Unknown axis")

	void				move(axis axis, sign sign);
	void				move(glm::vec3 &target, axis axis, sign sign);
	void				rotate(axis axis, sign sign);
	void				rotate(glm::vec3 &target, axis axis, sign sign);

	const glm::mat4		&view();
	const glm::mat4		projection;

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

	glm::mat4			matrix_rotation = glm::mat4(1);
	glm::mat4			matrix_view = glm::mat4();

	glm::vec3			position = glm::vec3();

	const float			movement_speed = MOD1_CAMERA_MOVEMENT_SPEED;
	const float			rotation_speed = MOD1_CAMERA_ROTATION_SPEED;

	void 				update_transformation();
};


