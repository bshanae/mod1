#pragma once

#include "mod1_main/mod1_OpenGL.h"
#include "mod1_main/mod1_macros.h"
#include "mod1_main/mod1_control.h"
#include "mod1_main/mod1_generic.h"

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

namespace			mod1_engine_gl
{
	template		<typename type>
	class			buffer;
	template		<typename type>
	class			buffer2;
	template		<typename type>
	class			point2;
	template		<typename type>
	class			point3;

	class			core;

	class			shader;
	enum class		shader_type;
	class			uniform;
	class			program;

	class			callback;
	class			renderer;

	class			loader;

	class			model_data;
	class			model;
	class			model_reader;

	class			texture;
	class 			framebuffer;

	class			camera;
	enum class		axis;
	enum class		sign;
}