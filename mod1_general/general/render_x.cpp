#include "general.h"

void				general::render_blur()
{
	framebuffer.bind();
	render();
	mod1_engine_gl::framebuffer::unbind();

	blur.program.start();
	framebuffer.texture().bind();
	mod1_engine_gl::texture::activate();
	blur.program.texture.upload(0);
	blur.square.draw();
	mod1_engine_gl::texture::unbind();
	program::stop();
}

void				general::render_gui()
{
	glDisable(GL_DEPTH_TEST);
	system.render();
	glEnable(GL_DEPTH_TEST);
	core::swap_buffers();
}