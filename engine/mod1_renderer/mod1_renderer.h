#pragma once

#include "mod1_OpenGL.h"
#include "mod1_control.h"

#include "mod1_core.h"
#include "mod1_program.h"
#include "mod1_model.h"
#include "mod1_cube.h"
#include "mod1_loader.h"
#include "mod1_camera.h"
#include "mod1_callback.h"
#include "mod1_point3.h"

#include <fstream>
#include <sstream>
#include <cmath>

class							mod1_renderer
{

public :

								mod1_renderer();
								~mod1_renderer() = default;

	void						add_callback(mod1_callback::functor_type functor, void *ptr);

	void						load_model(mod1_model *model);

	void						render();
	void						loop();

	typedef struct
	{
		float 					ambient_intensity;
		glm::vec3				point_position;
		float					point_intensity;
		float					point_power;
	}							mod1_light_info;

private :

	static void					glfw_callback(GLFWwindow* window, int key, int code, int action, int mode);

	std::vector<mod1_model *>	model_array;
	std::vector<mod1_callback>	callback_array;
	bool						render_request = true;

	mod1_core					core;
	mod1_program				program;
	mod1_loader					loader;
	mod1_camera					camera;

	mod1_light_info				light_info;
	mod1_cube					light_cube;

	GLuint						uniform_object_transformation;
	GLuint						uniform_camera_view;
	GLuint						uniform_camera_projection;
	GLuint						uniform_light_ambient_intensity;
	GLuint						uniform_light_point_position;
	GLuint						uniform_light_point_intensity;
	GLuint						uniform_light_point_power;

	void						render_internal();

};

