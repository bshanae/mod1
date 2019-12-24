#pragma once

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
};


