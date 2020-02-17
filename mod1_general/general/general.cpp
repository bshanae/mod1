#include "general.h"

MOD1_GENERATE_EXCEPTION_DEFINITION(general, exception_arguments)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(general, terrain)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(general, water)

						general::general(int argc, char **argv) :
						mod1_engine_gl::renderer(),
						cl_core(),
						framebuffer(window_width(), window_height()),
						program(),
						light_info(),
						system(*(mod1_engine_gl::core *)this)
{
MOD1_GENERATE_MESSAGE("")

	light_info.ambient_intensity = MOD1_GENERAL_LIGHT_AMBIENT_INTENSITY;
	light_info.direct_direction = glm::vec3(MOD1_GENERAL_LIGHT_DIRECT_DIRECTION);
	light_info.direct_intensity = MOD1_GENERAL_LIGHT_DIRECT_INTENSITY;

	MOD1_INTERNAL(terrain) = new mod1_algorithm::terrain;
MOD1_GENERATE_MESSAGE("Mod1 General : Terrain is created")
	MOD1_INTERNAL(water) = new mod1_algorithm::water(cl_core, MOD1_INTERNAL(terrain));
MOD1_GENERATE_MESSAGE("Mod1 General : Water is created")

	if (argc < 2)
		throw (exception_arguments());
	first_argument = argv[1];
	second_argument = argc >= 3 ? argv[2] : nullptr;

	font_gill_sans = new mod1_gui::font(MOD1_GENERAL_FONT_SOURCE, MOD1_GENERAL_FONT_WIDTH);
	gui_level = level::render;

	add_callback(mod1_engine_gl::event_type::key_press, general::functor_key, this);
	callback_rotate_start = add_callback(mod1_engine_gl::event_type::mouse_drag, general::functor_rotate_start, this);
	callback_rotate_finish = add_callback(mod1_engine_gl::event_type::mouse_release, general::functor_rotate_finish, this);

MOD1_GENERATE_MESSAGE("Mod1 General : Callbacks are set")

	timer_gravity = add_timer(1. / 35., functor_gravity, this);
	timer_gravity->block(true);

MOD1_GENERATE_MESSAGE("Mod1 General : Timers are set")

	mod1_gui::button	*button[10];

	button[0] = system.generate_button(window_width() / 2, window_height() * 1 / 5, "Continue", font_gill_sans, functor_continue, this);
	button[1] = system.generate_button(window_width() / 2, window_height() * 2 / 5, "Scenario", font_gill_sans, functor_scenarios, this);
	button[2] = system.generate_button(window_width() / 2, window_height() * 3 / 5, "Controls", font_gill_sans, nullptr, this);
	button[3] = system.generate_button(window_width() / 2, window_height() * 4 / 5, "Exit", font_gill_sans, functor_exit, this);

	button[4] = system.generate_button(window_width() / 2, window_height() * 1 / 7, "Rain", font_gill_sans, scenario_rain, this);
	button[5] = system.generate_button(window_width() / 2, window_height() * 2 / 7, "Heavy rain", font_gill_sans, scenario_heavy_rain, this);
	button[6] = system.generate_button(window_width() / 2, window_height() * 3 / 7, "Well", font_gill_sans, scenario_well, this);
	button[7] = system.generate_button(window_width() / 2, window_height() * 4 / 7, "Wave", font_gill_sans, scenario_wave, this);
	button[8] = system.generate_button(window_width() / 2, window_height() * 5 / 7, "4 waves", font_gill_sans, scenario_4_waves, this);
	button[9] = system.generate_button(window_width() / 2, window_height() * 6 / 7, "Flood", font_gill_sans, nullptr, this);

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
}