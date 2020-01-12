#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_control.h"
#include "mod1_main/mod1_generic.h"

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

	typedef struct
	{
		float 					ambient_intensity;
		glm::vec3				point_position;
		float					point_intensity;
		float					point_power;
	}							mod1_light_info;

	mod1_light_info				light_info;

	const core					*core_ptr;
	const program				*program_ptr;
	const loader				*loader_ptr;
	const camera				*camera_ptr;

	void						render();

private :

	class 						program : public mod1_engine::program
	{
	public :
		MOD1_GENERATE_UNIFORM(object_transformation)
		MOD1_GENERATE_UNIFORM(camera_view)
		MOD1_GENERATE_UNIFORM(camera_projection)
		MOD1_GENERATE_UNIFORM(light_ambient_intensity)
		MOD1_GENERATE_UNIFORM(light_point_position)
		MOD1_GENERATE_UNIFORM(light_point_intensity)
		MOD1_GENERATE_UNIFORM(light_point_power)
	};

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

	core						core;
	program						program;
	loader						loader;
	camera						camera;

	cube						light_cube;
};
