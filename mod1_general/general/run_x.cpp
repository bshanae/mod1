#include "general.h"

void				general::run_blur()
{
	framebuffer.bind();
	render();
	mod1_engine_gl::framebuffer::unbind();

	mod1_engine_gl::core::use_depth_test(false);

	blur.program.start();
	framebuffer.texture().bind();
	mod1_engine_gl::texture::activate();
	blur.program.texture.upload(0);
	blur.square.draw();
	mod1_engine_gl::texture::unbind();
	program::stop();

	mod1_engine_gl::core::use_depth_test(true);
}

void				general::run_gui_front()
{
	layout_scenarios.deactivate();
	layout_front.activate();
	system.render(layout_front);
	gui_level = level::menu_a;
}

void				general::run_gui_scenarios()
{
	layout_front.deactivate();
	layout_scenarios.activate();
	system.render(layout_scenarios);
	gui_level = level::menu_b;
}