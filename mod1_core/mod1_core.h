#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"

class					mod1_core
{

public :

	explicit mod1_core(const mod1_error &error);

	~mod1_core();

	GLFWwindow			*get_window() const;


private :

	const mod1_error	&error;
	const std::string	window_name = "Mod1";
	const int 			window_width = 720;
	const int 			window_height = 480;
	GLFWwindow			*window;

};
