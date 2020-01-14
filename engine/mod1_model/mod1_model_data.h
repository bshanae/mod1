#pragma once

#include "mod1_OpenGL.h"
#include "mod1_generate_x.h"

#include "mod1_buffer.h"

class					mod1_model_data
{

public :

						mod1_model_data() = default;
						~mod1_model_data() = default;

	mod1_buffer<float>	point_buffer;
	mod1_buffer<int>	index_buffer;
	mod1_buffer<float>	normal_buffer;
	mod1_buffer<float>	color_buffer;

	GLuint				vao = 0;
	GLuint				vbo_point = 0;
	GLuint				vbo_normal = 0;
	GLuint				vbo_color = 0;

	MOD1_GENERATE_EXCEPTION_DEFINITION(exception_unknown_slot, "Mod1 Model Data : Unknown slot")

	typedef enum
	{
		slot_point,
		slot_index,
		slot_normal,
		slot_color
	}					slot_type;

	void 				*get_ptr(const int &index, const slot_type &slot);
	void const			*get_ptr(const int &index, const slot_type &slot) const;
	bool				is_valid(const int &index, const slot_type &slot) const;
};


