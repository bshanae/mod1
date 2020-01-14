#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_control.h"
#include "mod1_main/mod1_generic.h"

#include "mod1_engine/namespace.h"

class					mod1_engine::camera
{
public :

						camera(
						int screen_width,
						int screen_height,
						const glm::vec3 &position = glm::vec3(0, 0, 0));
						~camera() = default;

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_axis, "Mod1 Camera : Unknown axis")

	typedef enum
	{
		mod1_axis_x,
		mod1_axis_y,
		mod1_axis_z
	}					mod1_axis;

	typedef enum :		int
	{
		mod1_negative = -1,
		mod1_positive = 1
	}					mod1_sign;

	void				move(mod1_axis axis, mod1_sign sign, glm::vec3 *target = nullptr);
	void				rotate(mod1_axis axis, mod1_sign sign);

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


