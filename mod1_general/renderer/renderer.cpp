#include "renderer.h"

					::renderer::renderer() :
					mod1_engine_gl::renderer(),
					framebuffer(core.window_width(), core.window_height()),
					program_main(),
					program_blur(),
					program_text(),
					light_info()

{
	light_info.ambient_intensity = MOD1_LIGHT_AMBIENT_INTENSITY;
	light_info.direct_direction = glm::vec3(MOD1_LIGHT_DIRECT_DIRECTION);
	light_info.direct_intensity = MOD1_LIGHT_DIRECT_INTENSITY;
}

void				::renderer::render_call()
{
	core::clear(MOD1_BACKGROUND);

	program_main.start();

	program_main.camera_projection.upload(camera.projection());
	program_main.camera_view.upload(camera.view());

	program_main.light_ambient_intensity.upload(light_info.ambient_intensity);
	program_main.light_direct_direction.upload(light_info.direct_direction);
	program_main.light_direct_intensity.upload(light_info.direct_intensity);

	for (auto &model : model_array())
	{
		program_main.object_transformation.upload(model->transformation());
		model->draw();
	}
	program::stop();
	core.swap_buffers();

	render();
}