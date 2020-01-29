#include "renderer.h"

using namespace			mod1_engine_gl;

						renderer::renderer() :
						camera(core.window_width(), core.window_height(), glm::vec3(MOD1_CAMERA_POSITION))
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

//	framebuffer.attach_texture(core.window_width(), core.window_height());

	buffer<float>		buffer;

	buffer.allocate(18);

	const float			raw[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f,  1.0f, 0.0f
	};

	buffer.copy(raw);

	blur_vao = loader.vao_build();
	loader.vao_edit_attribute(blur_vao, 0, 3, GL_FLOAT, buffer);

	test.build();
	load_model(&test);
}