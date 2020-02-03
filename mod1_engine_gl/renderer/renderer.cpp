#include "renderer.h"

using namespace			mod1_engine_gl;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(renderer, model_array)

						renderer::renderer() :
						core(),
						camera(core.window_width(), core.window_height(), glm::vec3(MOD1_CAMERA_POSITION))
{
	core.set_callback(glfw_callback, this);
}