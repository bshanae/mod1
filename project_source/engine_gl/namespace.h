#pragma once

#include "common/mod1_OpenGL.h"
#include "common/mod1_definition.h"
#include "common/mod1_control.h"
#include "common/mod1_generic.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <thread>

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
	template		<typename type>
	class			point4;

	class			core;

	class			shader;
	enum class		shader_type;
	class			uniform;
	class			program;

	enum class		event_type;
	class			event;

	typedef	void	(*functor_ptr)(void *ptr);
	typedef	void	(*functor_ptr_event)(void *ptr, const event &event);

	enum class		functor_type;

	class			callback;
	class			timer;

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