#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/buffer/buffer.h"

class					mod1_engine_gl::model_data
{

public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_unknown_slot, "Mod1 Engine GL, Model Data : Unknown slot")

						model_data() = default;
						~model_data() = default;

	buffer<float>		point_buffer;
	buffer<int>			index_buffer;
	buffer<float>		normal_buffer;
	buffer<float>		color_buffer;

	unsigned int		vao = 0;
	unsigned int		vbo_point = 0;
	unsigned int		vbo_normal = 0;
	unsigned int		vbo_color = 0;

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


