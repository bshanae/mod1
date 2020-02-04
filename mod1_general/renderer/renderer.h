#pragma once

#include "mod1_engine_gl/mod1_engine_gl.h"
#include "mod1_gui/mod1_gui.h"

#include "mod1_general/program_x/program_x.h"
#include "mod1_general/blur/blur.h"

using namespace		mod1_engine_gl;

class				renderer : public mod1_engine_gl::renderer
{
public :

					renderer();

	void			render_call() final;

private :

	framebuffer		framebuffer;

	class			program : public mod1_engine_gl::program
	{
	public :

					program();

	MOD1_GENERATE_UNIFORM(object_transformation, "object_transformation")
	MOD1_GENERATE_UNIFORM(camera_view, "camera_view")
	MOD1_GENERATE_UNIFORM(camera_projection, "camera_projection")
	MOD1_GENERATE_UNIFORM(light_ambient_intensity, "light_info.ambient_intensity")
	MOD1_GENERATE_UNIFORM(light_direct_direction, "light_info.direct_direction")
	MOD1_GENERATE_UNIFORM(light_direct_intensity, "light_info.direct_intensity")
	}				program;

	blur			blur;

	struct
	{
		float 		ambient_intensity;
		glm::vec3	direct_direction;
		float		direct_intensity;
	}				light_info;


	static void		callback(const class event &event, void *ptr);
};


