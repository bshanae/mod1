#pragma once

#include "mod1_OpenGL.h"
#include "mod1_control.h"
#include "mod1_exception.h"

#include <string>

class					mod1_core
{

public :

	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_logic_object, "Mod1 Core : Can't create more than one core")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_logic_callback, "Mod1 Core : Can't create more than one callback")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_window, "Mod1 Core : Can't initialize window")
	MOD1_EXCEPTION_GENERATE_DEFINITION(exception_GLEW, "Mod1 Core : Can't initialize GLEW")

	typedef void		(* mod1_callback)(GLFWwindow *, int, int, int, int);

						mod1_core();
						~mod1_core();

	int					window_width();
	int					window_height();

	bool				is_working();
	void				update();
	void				swap_buffers();
	void				set_callback(mod1_callback function, void *ptr);

private :

	const std::string	window_name = "Mod1";
	GLFWwindow			*window;
	const int 			window_width_internal = 720;
	const int 			window_height_internal = 480;
};
