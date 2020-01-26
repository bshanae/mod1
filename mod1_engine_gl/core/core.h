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

	int					window_width();
	int					window_height();

	bool				is_working();
	void 				terminate();
	void				update();
	void 				clear(const point3<float> &color);
	void 				draw(const int &vertex_number);
	void				swap_buffers();
	void				set_callback(mod1_callback function, void *ptr);

private :

	const std::string	window_name = "Mod1";
	GLFWwindow			*window;
	const int 			window_width_internal = MOD1_WINDOW_WIDTH;
	const int 			window_height_internal = MOD1_WINDOW_HEIGHT;
};
