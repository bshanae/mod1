#include "renderer.h"

using namespace			mod1_engine_gl;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(renderer, model_array)

						renderer::renderer() :
						core(),
						camera(window_width(), window_height(), glm::vec3(MOD1_CAMERA_POSITION))
{
	add_callback(event_type::key_press, functor_key, this);
	add_callback(event_type::key_hold, functor_key, this);

	timer = add_timer(1. / 60., functor_render, this);
}