#include "model_reader.h"

using namespace			mod1_engine_gl;

						model_reader::model_reader(const model &model) :
						object(model)
{}

						model_reader::model_reader(const model *model) :
						object(*model)
{}

const buffer<float>		&model_reader::point_buffer()
{
	return (object.data.point_buffer);
}

const buffer<int>		&model_reader::index_buffer()
{
	return (object.data.index_buffer);
}

const buffer<float>		&model_reader::normal_buffer()
{
	return (object.data.normal_buffer);
}

const buffer<float>		&model_reader::color_buffer()
{
	return (object.data.color_buffer);
}
