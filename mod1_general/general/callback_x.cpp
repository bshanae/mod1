#include "general.h"

void				general::callback_key(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;

	if (event.read_type() != mod1_engine_gl::event_type::key_press)
		return ;
	if (event.read_key() == GLFW_KEY_5)
	{
		general->framebuffer.bind();
		general->render();
		mod1_engine_gl::framebuffer::unbind();

		general->blur.program.start();
		general->framebuffer.texture().bind();
		mod1_engine_gl::texture::activate();
		general->blur.program.texture.upload(0);
		general->blur.square.draw();
		mod1_engine_gl::texture::unbind();
		program::stop();

		core::swap_buffers();
	}
	else if (event.read_key() == GLFW_KEY_6)
	{
		mod1_engine_gl::core::clear(mod1_engine_gl::point3<float>(0.5));
		general->system.render();
		core::swap_buffers();
	}
}

void				general::callback_drag(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;
	float			angle;

	angle = -1 * (event.read_diff().x / (float)general->window_width()) * general->rotation_speed;
	general->rotation = glm::rotate(general->rotation, glm::radians(angle), general->rotation_axis);

	general->render();
}

void				general::callback_water(void *ptr, const mod1_engine_gl::event &event)
{
	auto 			*general = (::general *)ptr;

	mod1_algorithm::water::callback(event, general->MOD1_INTERNAL(water));
	general->render();
}