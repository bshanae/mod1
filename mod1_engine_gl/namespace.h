#pragma once

#include "mod1_common/mod1_OpenGL.h"
#include "mod1_common/mod1_macros.h"
#include "mod1_common/mod1_control.h"
#include "mod1_common/mod1_generic.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

namespace			mod1_engine_gl
{

MOD1_GENERATE_EXCEPTION(exception_enum, "Mod1 Engine GL : Unknown enum value")

	template		<typename type>
	class			buffer;
	template		<typename type>
	class			buffer2;
	template		<typename type>
	class			point2;
	template		<typename type>
	class			point3;

	typedef void	(* glfw_callback)(GLFWwindow *, int, int, int, int);
	class			core;

	class			shader;
	enum class		shader_type;
	class			uniform;
	class			program;

	enum class		event_type;
	class			event;

	typedef	void	(*callback_functor)(const event &event, void *ptr);
	class			callback;

	class			renderer;

	class			vbo;
	class			vao;
	class			eab;

	enum class		model_slot;
	class			model;

	class			texture;
	enum class		texture_type;
	class 			framebuffer;

	class			camera;
	enum class		axis;
	enum class		sign;
}