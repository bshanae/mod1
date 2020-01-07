#pragma once

#include "mod1_OpenGL.h"

#include <string>

class					mod1_core
{

public :

	struct				exception_logic_object : public std::exception
	{
		const char		*what() const noexcept override;
	};

	struct				exception_logic_callback : public std::exception
	{
		const char		*what() const noexcept override;
	};

	struct				exception_window : public std::exception
	{
		const char		*what() const noexcept override;
	};

	struct				exception_GLEW : public std::exception
	{
		const char		*what() const noexcept override;
	};


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
