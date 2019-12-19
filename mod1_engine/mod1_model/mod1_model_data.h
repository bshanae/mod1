#pragma once

#include "mod1_point_2i.h"

class					mod1_model_data
{

public :

						mod1_model_data();
						~mod1_model_data();

	float				*point_array;
	int					point_array_length;
	int					*index_array;
	int					index_array_length;
};


