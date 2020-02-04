#pragma once

#include "mod1_engine_gl/mod1_engine_gl.h"

using namespace				mod1_engine_gl;

class						program_main : public program
{
public :

							program_main();

	MOD1_GENERATE_UNIFORM(object_transformation, "object_transformation")
	MOD1_GENERATE_UNIFORM(camera_view, "camera_view")
	MOD1_GENERATE_UNIFORM(camera_projection, "camera_projection")
	MOD1_GENERATE_UNIFORM(light_ambient_intensity, "light_info.ambient_intensity")
	MOD1_GENERATE_UNIFORM(light_direct_direction, "light_info.direct_direction")
	MOD1_GENERATE_UNIFORM(light_direct_intensity, "light_info.direct_intensity")
};

class						program_blur : public program
{
public :

							program_blur();

	MOD1_GENERATE_UNIFORM(texture, "uniform_texture")
};

class						program_text : public program
{
public :

							program_text();

	MOD1_GENERATE_UNIFORM(texture, "uniform_texture")
	MOD1_GENERATE_UNIFORM(color, "uniform_color")
	MOD1_GENERATE_UNIFORM(projection, "uniform_projection")
};