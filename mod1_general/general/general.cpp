#include "general.h"

MOD1_GENERATE_EXCEPTION_DEFINITION(general, exception_arguments)
MOD1_GENERATE_EXCEPTION_DEFINITION(general, exception_level)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(general, terrain)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(general, water)

						general::general(int argc, char **argv) :
							mod1_engine_gl::renderer(),
							cl_core(),
							framebuffer(window_width(), window_height()),
							program(),
							light(),
							system(*(mod1_engine_gl::core *)this)
{
MOD1_GENERATE_MESSAGE("")

	light.ambient_intensity = MOD1_GENERAL_LIGHT_AMBIENT_INTENSITY;
	light.direct_direction = glm::vec3(MOD1_GENERAL_LIGHT_DIRECT_DIRECTION);
	light.direct_intensity = MOD1_GENERAL_LIGHT_DIRECT_INTENSITY;

	MOD1_INTERNAL(terrain) = new mod1_algorithm::terrain;
MOD1_GENERATE_MESSAGE("Mod1 General : Terrain is created")
	MOD1_INTERNAL(water) = new mod1_algorithm::water(cl_core, MOD1_INTERNAL(terrain));
MOD1_GENERATE_MESSAGE("Mod1 General : Water is created")

	if (argc < 2)
		throw (exception_arguments());
	first_argument = argv[1];
	second_argument = argc >= 3 ? argv[2] : nullptr;

	font_main = new mod1_gui::font(MOD1_GENERAL_GILL_SANS, (int)(48 * window_multiplier()), point3<int>(45));
	font_title = new mod1_gui::font(MOD1_GENERAL_GILL_SANS, (int)(110 * window_multiplier()), point3<int>(45));
	font_light = new mod1_gui::font(MOD1_GENERAL_GILL_SANS, (int)(48 * window_multiplier()), point3<int>(120));
	level = gui_level::render;

	hint_label = system.generate_label(window_width() / 2, window_height() * 9 / 10, "", font_light);
	hint_layout.push(hint_label);

	add_callback(mod1_engine_gl::event_type::key_press, general::functor_key, this);
	callback_rotate_start = add_callback(mod1_engine_gl::event_type::mouse_drag, general::functor_rotate_start, this);
	callback_rotate_finish = add_callback(mod1_engine_gl::event_type::mouse_release, general::functor_rotate_finish, this);

	callback_light_a = add_callback(mod1_engine_gl::event_type::key_press, general::functor_light_rotate, this);
	callback_light_b = add_callback(mod1_engine_gl::event_type::key_hold, general::functor_light_rotate, this);
	callback_light_a->block(true);
	callback_light_b->block(true);

MOD1_GENERATE_MESSAGE("Mod1 General : Callbacks are set")

	timer_default_render = add_timer(1. / 10., general::functor_default_render, this);

	timer_gravity = add_timer(1. / 35., functor_gravity, this);
	timer_gravity->block(true);

MOD1_GENERATE_MESSAGE("Mod1 General : Timers are set")

	mod1_gui::label		*name;
	mod1_gui::button	*button[10];

	name = system.generate_label(window_width() / 2, window_height() * 2 / 10, "mod1", font_title);

	button[0] = system.generate_button(window_width() / 2, window_height() * 4 / 9, "Continue", font_main, functor_continue, this);
	button[1] = system.generate_button(window_width() / 2, window_height() * 5 / 9, "Scenario", font_main, functor_scenarios, this);
	button[2] = system.generate_button(window_width() / 2, window_height() * 6 / 9, "Light control", font_main, functor_light_control, this);
	button[3] = system.generate_button(window_width() / 2, window_height() * 7 / 9, "Exit", font_main, functor_exit, this);

	button[4] = system.generate_button(window_width() / 2, window_height() * 2 / 9, "Rain", font_main, scenario_rain, this);
	button[5] = system.generate_button(window_width() / 2, window_height() * 3 / 9, "Heavy rain", font_main, scenario_heavy_rain, this);
	button[6] = system.generate_button(window_width() / 2, window_height() * 4 / 9, "Well", font_main, scenario_well, this);
	button[7] = system.generate_button(window_width() / 2, window_height() * 5 / 9, "Wave", font_main, scenario_wave, this);
	button[8] = system.generate_button(window_width() / 2, window_height() * 6 / 9, "Four waves", font_main, scenario_four_waves, this);
	button[9] = system.generate_button(window_width() / 2, window_height() * 7 / 9, "Flood", font_main, scenario_flood, this);

	layout_front.push(name);
	for (int i = 0; i < 4; i++)
		layout_front.push(button[i]);
	for (int i = 4; i < 10; i++)
		layout_scenarios.push(button[i]);

MOD1_GENERATE_MESSAGE("Mod1 General : Buttons are set")
MOD1_GENERATE_MESSAGE("Mod1 General : Ready")
}

					general::~general()
{
	delete MOD1_INTERNAL(terrain);
	delete MOD1_INTERNAL(water);

	delete font_main;
	delete font_light;
	delete font_title;

	delete callback_rotate_start;
	delete callback_rotate_finish;
	delete callback_light_a;
	delete callback_light_b;

	delete timer_default_render;
	delete timer_gravity;
	delete timer_scenario;
}