#include "general.h"

void 				general::script_esc(const bool &state)
{
	if (state)
	{
		hint_mod = false;
		hint_drag = false;
		hint_light = false;

		script_blur();
		script_gui_front();

		callback_rotate_start->block(true);
		callback_rotate_finish->block(true);

		callback_light_a->block(true);
		callback_light_b->block(true);

		timer_default_render->block(true);

		if (timer_scenario)
			timer_scenario->block(true);
		timer_gravity->block(true);

		request_render(false);
	}
	else
	{
		layout_front.deactivate();
		layout_scenarios.deactivate();

		callback_rotate_start->block(false);
		callback_rotate_finish->block(false);

		timer_default_render->block(true);

		if (timer_scenario)
			timer_scenario->block(false);

		gui_level = level::render;
		request_render();
	}
}

void				general::script_blur()
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

void				general::script_gui_front()
{
	layout_scenarios.deactivate();
	layout_front.activate();
	system.render(layout_front);
	gui_level = level::menu_a;
}

void				general::script_gui_scenarios()
{
	layout_front.deactivate();
	layout_scenarios.activate();
	system.render(layout_scenarios);
	gui_level = level::menu_b;
}