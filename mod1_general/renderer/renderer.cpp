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

	square_blur.build();
	square_blur.load();

	square_text.set_as_dynamic();
	square_text.build();
	square_text.load();

	add_callback((mod1_engine_gl::callback::functor_type)(::renderer::callback), this);
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
}

void				::renderer::callback(const class event &event, void *ptr)
{
	auto 			*renderer = (::renderer *)ptr;

	if (event.read_type() != event_type::press)
		return ;
	if (event.read_key() == GLFW_KEY_5)
	{
		renderer->framebuffer.bind();
		renderer->render_call();
		framebuffer::unbind();

		renderer->program_blur.start();
		renderer->framebuffer.texture().bind();
		texture::activate();
		renderer->program_blur.texture.upload(0);
		renderer->square_blur.draw();
		texture::unbind();
		program::stop();

		renderer->core.swap_buffers();
	}
}