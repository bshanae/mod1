#include "renderer.h"

					::renderer::renderer() :
					mod1_engine_gl::renderer(),
					framebuffer(core.window_width(), core.window_height()),
					program(),
					light_info()

{
	light_info.ambient_intensity = MOD1_LIGHT_AMBIENT_INTENSITY;
	light_info.direct_direction = glm::vec3(MOD1_LIGHT_DIRECT_DIRECTION);
	light_info.direct_intensity = MOD1_LIGHT_DIRECT_INTENSITY;

	add_callback((mod1_engine_gl::callback::functor_type)(::renderer::callback), this);
}