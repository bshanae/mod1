#pragma once

#include "mod1_main/mod1_generic.h"

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
	class			camera;
	enum class		axis;
	enum class		sign;
}