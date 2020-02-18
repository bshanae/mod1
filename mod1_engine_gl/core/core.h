#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/point/point3.h"
#include "mod1_engine_gl/event/event.h"
#include "mod1_engine_gl/callback/callback.h"
#include "mod1_engine_gl/timer/timer.h"
#include "mod1_engine_gl/core/global.h"

class					mod1_engine_gl::core
{

public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_logic_object, "Mod1 Engine GL, Core : Can't create more than one core")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_window, "Mod1 Engine GL, Core : Can't initialize window")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_GLEW, "Mod1 Engine GL, Core : Can't initialize GLEW")

						core();
	virtual				~core();

	void				start();
	void				finish();

	callback			*add_callback(const event_type &type, functor_ptr_event functor, void *ptr);
	callback			*add_callback(const event_type &type, functor_ptr functor, void *ptr);
	void				remove_callback(callback *callback);

	timer				*add_timer(const double &period, functor_ptr functor, void *ptr);
	void 				remove_timer(timer *timer);

	static void 		show_polygon_back(const bool &state);
	static void 		use_depth_test(const bool &state);
	static double		time();

	static void 		clear(const point3<float> &color);
	static void 		draw(const int &count);
	static void			swap_buffers();

private :

	const std::string	window_name = MOD1_WINDOW_NAME;
	GLFWwindow			*window;

	static void 		glfw_callback_key(GLFWwindow* window, int key, int code, int action, int mode);
	static void 		glfw_callback_mouse_movement(GLFWwindow* window, double x, double y);
	static void 		glfw_callback_mouse_key(GLFWwindow* window, int key, int action, int mode);

MOD1_GENERATE_INTERNAL_WITH_VALUE(int, window_width, MOD1_WINDOW_WIDTH)
MOD1_GENERATE_INTERNAL_WITH_VALUE(int, window_height, MOD1_WINDOW_HEIGHT)

	event				event;

#define CALLBACK_MAP	std::map<event_type, std::vector<callback *>>
	CALLBACK_MAP		callback_map;

	void 				launch_signal();

#define TIMER_VECTOR	std::vector<timer *>
	TIMER_VECTOR		timer_vector;

	void				test_timer();

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(window_width)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(window_height)
};
