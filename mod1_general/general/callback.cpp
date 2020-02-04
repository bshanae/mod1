#include "general.h"

void				general::callback(const mod1_engine_gl::event &event, void *ptr)
{
	auto 			*general = (::general *)ptr;

	if (event.read_type() != mod1_engine_gl::event_type::press)
		return ;
	if (event.read_key() == GLFW_KEY_5)
	{
		general->framebuffer.bind();
		general->render_call();
		mod1_engine_gl::framebuffer::unbind();

		general->blur.program.start();
		general->framebuffer.texture().bind();
		mod1_engine_gl::texture::activate();
		general->blur.program.texture.upload(0);
		general->blur.square.draw();
		mod1_engine_gl::texture::unbind();
		program::stop();

		general->core.swap_buffers();
	}
	else if (event.read_key() == GLFW_KEY_6)
	{
		mod1_engine_gl::core::clear(mod1_engine_gl::point3<float>(0.5));

		general->system.write("Hello there", mod1_engine_gl::point2<int>(100, 100));

		general->core.swap_buffers();
	}
}