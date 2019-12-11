#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"
#include "mod1_core.h"
#include "mod1_program.h"

#include <fstream>
#include <sstream>
#include <cmath>


class					mod1_drawer
{

public :

	explicit mod1_drawer(const mod1_error &error);

	~mod1_drawer();

	void				loop();

private :

	static void			callback_key(GLFWwindow* window, int key, int code, int action, int mode);

	const mod1_error	&error;
	const mod1_core		core;
	const mod1_program	program;
	GLuint 				vao;
	GLuint 				ebo;
	GLuint 				vbo;
};

