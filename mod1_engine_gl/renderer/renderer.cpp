#include "renderer.h"

using namespace			mod1_engine_gl;

						renderer::renderer() :
						light_info(),
						camera(core.window_width(), core.window_height(), glm::vec3(MOD1_CAMERA_POSITION)),
						framebuffer(core.window_width(), core.window_height())
{
	core.set_callback(glfw_callback, this);

	light_info.ambient_intensity = MOD1_LIGHT_AMBIENT_INTENSITY;
	light_info.direct_direction = glm::vec3(MOD1_LIGHT_DIRECT_DIRECTION);
	light_info.direct_intensity = MOD1_LIGHT_DIRECT_INTENSITY;

	main_program.add_shader(shader_type::vertex, MOD1_SOURCE_SHADER_VERTEX);
#if MOD1_NORMAL_TEST
	add_shader(shader_type::geometry, MOD1_SOURCE_SHADER_GEOMETRY);
#endif
	main_program.add_shader(shader_type::fragment, MOD1_SOURCE_SHADER_FRAGMENT);
	main_program.link();

	main_program.start();

	main_program.set_uniform(main_program.object_transformation);
	main_program.set_uniform(main_program.camera_view);
	main_program.set_uniform(main_program.camera_projection);
	main_program.set_uniform(main_program.light_ambient_intensity);
	main_program.set_uniform(main_program.light_direct_direction);
	main_program.set_uniform(main_program.light_direct_intensity);

	main_program.camera_projection.upload(camera.projection());

	main_program.stop();

	blur_program.add_shader(shader_type::vertex, "./source_gl/blur_vertex.glsl");
	blur_program.add_shader(shader_type::fragment, "./source_gl/blur_fragment.glsl");
	blur_program.link();

	blur_program.set_uniform(blur_program.texture);

	blur_square.build();
	blur_square.load(loader);
}