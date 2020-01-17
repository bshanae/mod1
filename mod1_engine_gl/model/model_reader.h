#pragma once

#include "mod1_engine_gl/model/model.h"

#include "mod1_engine_gl/namespace.h"

class						mod1_engine_gl::model_reader
{
public :
							model_reader(const model &model);
							model_reader(const model *model);
							~model_reader() = default;

	const buffer<float>		&point_buffer();
	const buffer<int>		&index_buffer();
	const buffer<float>		&normal_buffer();
	const buffer<float>		&color_buffer();

private :

	const model				&object;
};


