#pragma once

#include "mod1_buffer.h"

class					mod1_model_data
{

public :

						mod1_model_data() = default;
						~mod1_model_data() = default;

	mod1_buffer<float>	point_array;
	mod1_buffer<int>	index_array;
	mod1_buffer<float>	normal_array;
	mod1_buffer<float>	color_array;
};


