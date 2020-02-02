#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/vbo/vbo.h"
#include "mod1_engine_gl/vao/vao.h"
#include "mod1_engine_gl/eab/eab.h"

class					mod1_engine_gl::model_data
{

public :

						model_data() = default;
						~model_data() = default;

	buffer<float>		point_buffer;
	buffer<int>			index_buffer;
	buffer<float>		normal_buffer;
	buffer<float>		color_buffer;

	vao					*vao = nullptr;
	vbo					*vbo_point = nullptr;
	vbo					*vbo_normal = nullptr;
	vbo					*vbo_color = nullptr;
	eab					*eab = nullptr;

	enum class			slot_type
	{
		point,
		index,
		normal,
		color
	};

	void 				*get_ptr(const int &index, const slot_type &slot);
	void const			*get_ptr(const int &index, const slot_type &slot) const;
	bool				is_valid(const int &index, const slot_type &slot) const;
};


