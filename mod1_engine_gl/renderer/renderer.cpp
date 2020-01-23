#include "renderer.h"

using namespace			mod1_engine_gl;

						renderer::renderer() :
						camera(core.window_width(), core.window_height(), glm::vec3(MOD1_CAMERA_POSITION)),
						light_info()
{
	core.set_callback(glfw_callback, this);

	light_info.ambient_intensity = MOD1_LIGHT_AMBIENT_INTENSITY;
	light_info.direct_direction = glm::vec3(MOD1_LIGHT_DIRECT_DIRECTION);
	light_info.direct_intensity = MOD1_LIGHT_DIRECT_INTENSITY;

	program.add_shader(shader_type::vertex, MOD1_SOURCE_SHADER_VERTEX);
#if MOD1_NORMAL_TEST
	add_shader(shader_type::geometry, MOD1_SOURCE_SHADER_GEOMETRY);
#endif
	program.add_shader(shader_type::fragment, MOD1_SOURCE_SHADER_FRAGMENT);
	program.link();

	program.start();

	program.set_uniform(program.object_transformation);
	program.set_uniform(program.camera_view);
	program.set_uniform(program.camera_projection);
	program.set_uniform(program.light_ambient_intensity);
	program.set_uniform(program.light_direct_direction);
	program.set_uniform(program.light_direct_intensity);

	program.camera_projection.upload(camera.projection);

	program.stop();

}