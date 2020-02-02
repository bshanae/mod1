#pragma once

#include "mod1_main/mod1_macros.h"
#include "mod1_main/mod1_control.h"
#include "mod1_engine_gl/mod1_engine_gl.h"
#include "mod1_engine_cl/mod1_engine_cl.h"

#include "mod1_libraries/FastNoise/FastNoise.h"

#include <fstream>
#include <vector>
#include <iostream>

namespace			mod1_algorithm
{
	using			mod1_engine_gl::point2;
	using			mod1_engine_gl::point3;

	using			mod1_engine_gl::buffer;
	using			mod1_engine_gl::buffer2;

	using			model_slot = mod1_engine_gl::model_slot;

	class 			plane;
	enum class 		plane_color;
	class 			terrain;
	class 			water;
}