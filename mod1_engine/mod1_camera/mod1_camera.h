#pragma once

#include "mod1_OpenGL.h"

#include <exception>

class					mod1_camera
{
public :

						mod1_camera(
						int screen_width,
						int screen_height,
						const glm::vec3 &position = glm::vec3(0, 0, 0));
						~mod1_camera() = default;

	struct				exception_bad_axis : public std::exception
	{
		const char		*what() const noexcept override;
	};

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

	void				move(mod1_axis axis, mod1_sign sign, glm::vec3 *target = NULL);
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
	glm::mat4			matrix_view;

	glm::vec3			position;

	const float			movement_speed = 2.;
	const float			rotation_speed = 0.035;

	void 				update_transformation();
};


