#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/core/core.h"
#include "mod1_engine_gl/program/program.h"
#include "mod1_engine_gl/framebuffer/framebuffer.h"
#include "mod1_engine_gl/model/model.h"
#include "mod1_engine_gl/loader/loader.h"
#include "mod1_engine_gl/camera/camera.h"
#include "mod1_engine_gl/callback/callback.h"
#include "mod1_engine_gl/uniform/uniform.h"
#include "mod1_engine_gl/point/point3.h"

class							mod1_engine_gl::renderer
{

public :

								renderer();
								~renderer() = default;

	void						add_callback(callback::functor_type functor, void *ptr);

	void						load_model(model *model);

	void						render();

	void						loop();
	void						terminate();

private :

	static void					glfw_callback(GLFWwindow* window, int key, int code, int action, int mode);

	std::vector<model *>		model_array;
	std::vector<callback>		callback_array;
	bool						render_request = false;

	core						core;
	loader						loader;
	camera						camera;
	framebuffer					framebuffer;

	class						: public mod1_engine_gl::program
	{
	public :
		MOD1_GENERATE_UNIFORM(object_transformation, "object_transformation")
		MOD1_GENERATE_UNIFORM(camera_view, "camera_view")
		MOD1_GENERATE_UNIFORM(camera_projection, "camera_projection")
		MOD1_GENERATE_UNIFORM(light_ambient_intensity, "light_info.ambient_intensity")
		MOD1_GENERATE_UNIFORM(light_direct_direction, "light_info.direct_direction")
		MOD1_GENERATE_UNIFORM(light_direct_intensity, "light_info.direct_intensity")
	}							main_program;

	class						: public mod1_engine_gl::program
	{}							blur_program;

	struct
	{
		float 					ambient_intensity;
		glm::vec3				direct_direction;
		float					direct_intensity;
	}							light_info;

	unsigned int				blur_vao;

	void						render_internal();
	void						render_no_swap();
};

