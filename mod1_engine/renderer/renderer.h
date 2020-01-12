#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_control.h"

#include "mod1_engine/core/core.h"
#include "mod1_engine/program/program.h"
#include "mod1_engine/model/model.h"
#include "mod1_engine/loader/loader.h"
#include "mod1_engine/camera/camera.h"
#include "mod1_engine/point/point3.h"

#include <fstream>
#include <sstream>
#include <cmath>

class							mod1_engine::renderer
{

public :

								renderer();
								~renderer() = default;

	void						load_model(model *model);

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

	class						cube : private model
	{
	public :

		cube() = default;
		~cube() = default;

		void					build() final;
		model					*model();
		using					model::transformation;
	};


	static void					glfw_callback(GLFWwindow* window, int key, int code, int action, int mode);

	std::vector<model *>		model_array;
	bool						render_request = true;

	core						core;
	program						program;
	loader						loader;
	camera						camera;

	mod1_light_info				light_info;
	cube						light_cube;

	GLuint						uniform_object_transformation;
	GLuint						uniform_camera_view;
	GLuint						uniform_camera_projection;
	GLuint						uniform_light_ambient_intensity;
	GLuint						uniform_light_point_position;
	GLuint						uniform_light_point_intensity;
	GLuint						uniform_light_point_power;

	void						render_internal();

	GLuint						texture;
};

