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

class 					test : public mod1_engine_gl::model
{
public :
	void				build() override
	{

		GLfloat vertices[] = {
			0.5f,  0.5f, 0.0f,  // Верхний правый угол
			0.5f, -0.5f, 0.0f,  // Нижний правый угол
			-0.5f, -0.5f, 0.0f,  // Нижний левый угол
			-0.5f,  0.5f, 0.0f   // Верхний левый угол
		};
		GLuint indices[] = {  // Помните, что мы начинаем с 0!
			0, 1, 3,   // Первый треугольник
			1, 2, 3    // Второй треугольник
		};

		data.point_buffer.allocate(MOD1_PLANE_POINT_SIZE * 4);
		data.point_buffer.copy(vertices);

		data.index_buffer.allocate(MOD1_PLANE_INDEX_SIZE * 6);
		data.index_buffer.copy((int *)indices);

		data.normal_buffer.allocate(MOD1_PLANE_NORMAL_SIZE * 1);

		data.color_buffer.allocate(MOD1_PLANE_COLOR_SIZE * 1);

		set_as_built();
	}
};

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
	unsigned int				framebuffer;
	unsigned int				texture_color;
	unsigned int				texture_depth;


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
	class test					test;

	void						render_internal();
	void						render_no_swap();
};

