#pragma once

#include "mod1_engine_gl/mod1_engine_gl.h"
#include "mod1_algorithm/mod1_algorithm.h"
#include "mod1_gui/mod1_gui.h"

#include "mod1_general/blur/blur.h"

#include <random>

class									general : public mod1_engine_gl::renderer
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_arguments, "Mod1 Main : Invalid number of arguments")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_level, "Mod1 Main : Unknown GUI level")

										general(int argc, char **argv);
										~general() final;

	void								build();

private :

	char 								*first_argument = nullptr;
	char 								*second_argument = nullptr;

	MOD1_GENERATE_INTERNAL_WITH_VALUE(mod1_algorithm::terrain, *terrain, nullptr)
	MOD1_GENERATE_INTERNAL_WITH_VALUE(mod1_algorithm::water, *water, nullptr)

//										RENDERING

	void								render() final;

	mod1_engine_cl::core				cl_core;
	mod1_engine_gl::framebuffer			framebuffer;

	class								program : public mod1_engine_gl::program
	{
	public :

										program();

	MOD1_GENERATE_UNIFORM(object_transformation, "object.transformation")
	MOD1_GENERATE_UNIFORM(object_ambient_receptivity, "object.ambient_receptivity")
	MOD1_GENERATE_UNIFORM(object_diffuse_receptivity, "object.diffuse_receptivity")
	MOD1_GENERATE_UNIFORM(object_specular_receptivity, "object.specular_receptivity")
	MOD1_GENERATE_UNIFORM(camera_position, "camera.position")
	MOD1_GENERATE_UNIFORM(camera_view, "camera.view")
	MOD1_GENERATE_UNIFORM(camera_projection, "camera.projection")
	MOD1_GENERATE_UNIFORM(light_ambient_intensity, "light.ambient_intensity")
	MOD1_GENERATE_UNIFORM(light_direct_direction, "light.direct_direction")
	MOD1_GENERATE_UNIFORM(light_direct_intensity, "light.direct_intensity")
	}									program;

	struct
	{
		float 							ambient_intensity;
		glm::vec3						direct_direction;
		float							direct_intensity;
	}									light;

	const glm::vec3						rotation_axis = glm::vec3(0, 1, 0);
	const float							rotation_speed = 300;
	glm::mat4							rotation = glm::mat4(1);

//										GUI

	blur								blur;
	mod1_gui::system					system;

	mod1_gui::font						*font_main;
	mod1_gui::font						*font_light;
	mod1_gui::font						*font_title;

	mod1_gui::layout					layout_front;
	mod1_gui::layout					layout_scenarios;

	enum class							gui_level
	{
		render,
		menu_a,
		menu_b
	}									level;

	void								script_blur();
	void								script_gui_front();
	void								script_gui_scenarios();
	void								script_esc();

	typedef struct
	{
		bool							state_ever;
		bool							state_now;
		std::string						text;
	}									hint_config;

	void								hint_launch(hint_config &config);
	void								hint_render();

	const double						hint_timeout = 4;

	bool								hint_mod = false;
	double								hint_remain;
	double								hint_last_time;

	mod1_gui::label						*hint_label = nullptr;
	mod1_gui::layout					hint_layout;

	hint_config							hint_config_model = {false, false, "Drag mouse to rotate terrain"};
	hint_config							hint_config_light = {false, false, "Use W/A/S/D keys to control light direction"};

//										FUNCTORS

	static void							functor_key(void *ptr, const mod1_engine_gl::event &event);
	static void							functor_rotate_start(void *ptr, const mod1_engine_gl::event &event);
	static void							functor_rotate_finish(void *ptr);
	static void 						functor_default_render(void *ptr);

	static void							functor_continue(void *ptr);
	static void							functor_scenarios(void *ptr);
	static void							functor_light_control(void *ptr);
	static void							functor_exit(void *ptr);

	static void							functor_light_rotate(void *ptr, const mod1_engine_gl::event &event);

	static void							functor_gravity(void *ptr);
	static void							functor_well(void *ptr);
	static void							functor_rain(void *ptr);
	static void							functor_flood(void *ptr);

//										CALLBACKS

	mod1_engine_gl::callback			*callback_rotate_start = nullptr;
	mod1_engine_gl::callback			*callback_rotate_finish = nullptr;

	mod1_engine_gl::callback			*callback_light_a = nullptr;
	mod1_engine_gl::callback			*callback_light_b = nullptr;

//										TIMERS

	mod1_engine_gl::timer				*timer_default_render = nullptr;
	mod1_engine_gl::timer				*timer_gravity = nullptr;

	bool								gravity_block = true;

//										SCENARIOS

	mod1_engine_gl::timer				*timer_scenario = nullptr;
	std::default_random_engine			generator;

	bool								rain_double = false;
	std::uniform_int_distribution<int>	rain_distribution_x;
	std::uniform_int_distribution<int>	rain_distribution_y;

	std::uniform_int_distribution<int>	well_distribution_x;
	std::uniform_int_distribution<int>	well_distribution_y;
	point2<int>							well_position;

	float								flood_level = 0;

	static void							scenario_rain(void *ptr);
	static void							scenario_heavy_rain(void *ptr);
	static void							scenario_well(void *ptr);
	static void							scenario_wave(void *ptr);
	static void							scenario_4_waves(void *ptr);
	static void							scenario_flood(void *ptr);

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(terrain)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(water)
};


