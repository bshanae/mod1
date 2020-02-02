#include "model.h"

using namespace		mod1_engine_gl;

void				model::upload_slot(const model_slot &slot)
{
	if (slot == model_slot::point)
		vbo_point->buffer(point_buffer, is_dynamic);
	else if (slot == model_slot::normal)
		vbo_normal->buffer(normal_buffer, is_dynamic);
	else if (slot == model_slot::color)
		vbo_color->buffer(color_buffer, is_dynamic);
	else
		throw (exception_enum());
}