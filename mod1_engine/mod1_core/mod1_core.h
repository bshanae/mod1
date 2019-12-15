#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"


class					mod1_core
{

public :

	typedef void		(* mod1_callback)(GLFWwindow *, int, int, int, int);

	const int 			window_width = 720;
	const int 			window_height = 480;

						mod1_core();
						~mod1_core();

	bool				is_working();
	void				update();
	void				swap_buffers();
	void				set_callback(mod1_callback function, void *ptr);

private :

	const std::string	window_name = "Mod1";
	GLFWwindow			*window;
};
