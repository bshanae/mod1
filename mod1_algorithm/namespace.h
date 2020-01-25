#pragma once

#include "mod1_engine_gl/mod1_engine_gl.h"
#include "mod1_engine_cl/mod1_engine_cl.h"

namespace			mod1_algorithm
{
	using			mod1_engine_gl::point2;
	using			mod1_engine_gl::point3;

	using			mod1_engine_gl::buffer;
	using			mod1_engine_gl::buffer2;

	using			model_slot = mod1_engine_gl::model_data::slot_type;

	class 			plane;
	enum class 		plane_color;
	class 			terrain;
	class 			water;
}