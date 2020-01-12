#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_control.h"
#include "mod1_main/mod1_generic.h"

#include "mod1_engine/namespace.h"

#include "mod1_engine/point/point3.h"

#include <string>

class					mod1_engine::core
{

public :

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_logic_object, "Mod1 Engine, Core : Can't create more than one core")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_logic_callback, "Mod1 Engine, Core : Can't create more than one callback")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_window, "Mod1 Engine, Core : Can't initialize window")
	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_GLEW, "Mod1 Engine, Core : Can't initialize GLEW")

	typedef void		(* mod1_callback)(GLFWwindow *, int, int, int, int);

						core();
						~core();

	int					window_width() const;
	int					window_height() const;

	bool				is_working() const;
	void				update() const;
	void				clear(const point3<float> &color) const;
	void				swap_buffers() const;

	void				set_callback(mod1_callback function, void *ptr);

private :

	const std::string	window_name = "Mod1";
	GLFWwindow			*window;
	const int 			window_width_internal = MOD1_SCREEN_WIDTH;
	const int 			window_height_internal = MOD1_SCREEN_HEIGHT;
};
