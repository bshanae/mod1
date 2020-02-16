#include "general.h"

void				general::run_blur()
{
	framebuffer.bind();
	render();
	mod1_engine_gl::framebuffer::unbind();

	glDisable(GL_DEPTH_TEST);

	blur.program.start();
	framebuffer.texture().bind();
	mod1_engine_gl::texture::activate();
	blur.program.texture.upload(0);
	blur.square.draw();
	mod1_engine_gl::texture::unbind();
	program::stop();

	glEnable(GL_DEPTH_TEST);
}

void				general::run_gui_front()
{
	glDisable(GL_DEPTH_TEST);
	system.render(layout_front);
	core::swap_buffers();
	glEnable(GL_DEPTH_TEST);

	gui_level = level::menu_a;
}

void				general::run_gui_scenarios()
{
	glDisable(GL_DEPTH_TEST);
	system.render(layout_scenarios);
	core::swap_buffers();
	glEnable(GL_DEPTH_TEST);

	gui_level = level::menu_b;
}