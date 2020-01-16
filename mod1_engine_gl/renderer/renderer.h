#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_control.h"

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/core/core.h"
#include "mod1_engine_gl/program/program.h"
#include "mod1_engine_gl/model/model.h"
#include "mod1_engine_gl/loader/loader.h"
#include "mod1_engine_gl/camera/camera.h"
#include "mod1_engine_gl/callback/callback.h"
#include "mod1_engine_gl/uniform/uniform.h"
#include "mod1_engine_gl/point/point3.h"
#include "mod1_engine_gl/renderer/cube/cube.h"

#include <fstream>
#include <sstream>
#include <cmath>

class							mod1_engine_gl::renderer
{

public :

								renderer();
								~renderer() = default;

	void						add_callback(callback::functor_type functor, void *ptr);

	void						load_model(model *model);

	void						render();
	void						loop();

private :

	struct						light_info
	{
		float 					ambient_intensity;
		glm::vec3				point_position;
		float					point_intensity;
		float					point_power;
	};

	class						program : public mod1_engine_gl::program
	{
	public :
		MOD1_GENERATE_UNIFORM(object_transformation, "object_transformation")
		MOD1_GENERATE_UNIFORM(camera_view, "camera_view")
		MOD1_GENERATE_UNIFORM(camera_projection, "camera_projection")
		MOD1_GENERATE_UNIFORM(light_ambient_intensity, "light_info.ambient_intensity")
		MOD1_GENERATE_UNIFORM(light_point_position, "light_info.point_position")
		MOD1_GENERATE_UNIFORM(light_point_intensity, "light_info.point_intensity")
		MOD1_GENERATE_UNIFORM(light_point_power, "light_info.point_power")
	};

	static void					glfw_callback(GLFWwindow* window, int key, int code, int action, int mode);

	std::vector<model *>		model_array;
	std::vector<callback>		callback_array;
	bool						render_request = true;

	core						core;
	program						program;
	loader						loader;
	camera						camera;

	struct light_info			light_info;
	cube						light_cube;

	void						render_internal();
};

