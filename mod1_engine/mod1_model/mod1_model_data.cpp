#include "mod1_model_data.h"

mod1_model_data::mod1_model_data()
{
	point_array = nullptr;
	point_array_length = -1;
	index_array = nullptr;
	index_array_length = -1;
}

mod1_model_data::~mod1_model_data()
{
	delete[] point_array;
	delete[] index_array;
}
