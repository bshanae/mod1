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
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		general->system.write("");

		general->core.swap_buffers();
	}
}