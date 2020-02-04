#pragma once

#include "mod1_engine_gl/mod1_engine_gl.h"

#include "mod1_general/program_x/program_x.h"
#include "mod1_general/square/square.h"

using namespace		mod1_engine_gl;

class				renderer : public mod1_engine_gl::renderer
{
public :

					renderer();

	void			render_call() final;

private :

	framebuffer		framebuffer;

	program_main	program_main;
	program_blur	program_blur;
	program_text	program_text;

	struct
	{
		float 		ambient_intensity;
		glm::vec3	direct_direction;
		float		direct_intensity;
	}				light_info;

	square			square_blur;
	square			square_text;

	static void		callback(const class event &event, void *ptr);
};


