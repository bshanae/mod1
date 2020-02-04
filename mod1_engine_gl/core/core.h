#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/point/point3.h"

class					mod1_engine_gl::core
{

public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_logic_object, "Mod1 Engine GL, Core : Can't create more than one core")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_logic_callback, "Mod1 Engine GL, Core : Can't create more than one callback")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_window, "Mod1 Engine GL, Core : Can't initialize window")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_GLEW, "Mod1 Engine GL, Core : Can't initialize GLEW")

	typedef void		(* mod1_callback)(GLFWwindow *, int, int, int, int);

						core();
						~core();

	void				set_callback(mod1_callback function, void *ptr);
	static void			*get_callback_pointer(GLFWwindow* window);

	bool 				is_working();
	void 				terminate();
	void				swap_buffers();

	static void			update();
	static void 		clear(const point3<float> &color);
	static void 		draw(const int &count);

private :

	const std::string	window_name = "Mod1";
	GLFWwindow			*window;

MOD1_GENERATE_INTERNAL_WITH_VALUE(int, window_width, MOD1_WINDOW_WIDTH)
MOD1_GENERATE_INTERNAL_WITH_VALUE(int, window_height, MOD1_WINDOW_HEIGHT)

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(window_width)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(window_height)

};
