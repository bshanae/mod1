#include "renderer.h"

using namespace			mod1_engine;

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

	uniform_object_transformation = glGetUniformLocation(program.object(), "object_transformation");
	uniform_camera_view = glGetUniformLocation(program.object(), "camera_view");
	uniform_camera_projection = glGetUniformLocation(program.object(), "camera_projection");
	glUniformMatrix4fv(uniform_camera_projection, 1, GL_FALSE, glm::value_ptr(camera.projection));
	uniform_light_ambient_intensity = glGetUniformLocation(program.object(), "light_info.ambient_intensity");
	uniform_light_point_position = glGetUniformLocation(program.object(), "light_info.point_position");
	uniform_light_point_intensity = glGetUniformLocation(program.object(), "light_info.point_intensity");
	uniform_light_point_power = glGetUniformLocation(program.object(), "light_info.point_power");

	program.stop();

#if MOD1_ENABLED(MOD1_LIGHT_CUBE)
	light_cube.build();
	load_model(light_cube.model());
#endif

}