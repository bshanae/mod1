#include "renderer.h"

using namespace			mod1_engine_gl;

						renderer::renderer() :
						camera(core.window_width(), core.window_height(), MOD1_CAMERA_POSITION),
						light_info()
{
	core.set_callback(glfw_callback, this);

	light_info.ambient_intensity = MOD1_LIGHT_AMBIENT_INTENSITY;
	light_info.point_position = glm::vec3(MOD1_LIGHT_POINT_POSITION);
	light_info.point_intensity = MOD1_LIGHT_POINT_INTENSITY;
	light_info.point_power = 2.;

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
	program.set_uniform(program.light_point_position);
	program.set_uniform(program.light_point_intensity);
	program.set_uniform(program.light_point_power);

	program.camera_projection.upload(camera.projection);

	program.stop();

#if MOD1_ENABLED(MOD1_LIGHT_CUBE)
	light_cube.build();
	load_model(light_cube.model());
#endif
}