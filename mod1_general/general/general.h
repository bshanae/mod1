#pragma once

#include "mod1_engine_gl/mod1_engine_gl.h"
#include "mod1_algorithm/mod1_algorithm.h"
#include "mod1_gui/mod1_gui.h"

#include "mod1_general/blur/blur.h"

class							general : public mod1_engine_gl::renderer
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_arguments, "Mod1 Main : Invalid number of arguments")

								general(int argc, char **argv);
								~general() final;

	void						build();

	void						render() final;

private :

	mod1_engine_cl::core		cl_core;

	mod1_engine_gl::framebuffer	framebuffer;

	class						program : public mod1_engine_gl::program
	{
	public :

								program();

	MOD1_GENERATE_UNIFORM(object_transformation, "object.transformation")
	MOD1_GENERATE_UNIFORM(object_specular, "object.specular")
	MOD1_GENERATE_UNIFORM(camera_position, "camera.position")
	MOD1_GENERATE_UNIFORM(camera_view, "camera.view")
	MOD1_GENERATE_UNIFORM(camera_projection, "camera.projection")
	MOD1_GENERATE_UNIFORM(light_ambient_intensity, "light.ambient_intensity")
	MOD1_GENERATE_UNIFORM(light_direct_direction, "light.direct_direction")
	MOD1_GENERATE_UNIFORM(light_direct_intensity, "light.direct_intensity")
	}							program;

	blur						blur;

	struct
	{
		float 					ambient_intensity;
		glm::vec3				direct_direction;
		float					direct_intensity;
	}							light_info;

	const glm::vec3				rotation_axis = glm::vec3(0, 1, 0);
	const float					rotation_speed = 300;
	glm::mat4					rotation = glm::mat4(1);

	static void					callback_key(const mod1_engine_gl::event &event, void *ptr);
	static void					callback_drag(const mod1_engine_gl::event &event, void *ptr);
	static void					callback_water(const mod1_engine_gl::event &event, void *ptr);

	char 						*first_argument = nullptr;

MOD1_GENERATE_INTERNAL_WITH_VALUE(mod1_algorithm::terrain, *terrain, nullptr)
MOD1_GENERATE_INTERNAL_WITH_VALUE(mod1_algorithm::water, *water, nullptr)

	mod1_gui::system			system;

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(terrain)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(water)
};


