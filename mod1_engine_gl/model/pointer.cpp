#include "model.h"

using namespace		mod1_engine_gl;

void 				*model::pointer(const int &index, const model_slot &slot)
{
	if (slot == model_slot::point)
		return (&point_buffer[3 * index]);
	else if (slot == model_slot::index)
		return (&index_buffer[3 * index]);
	else if (slot == model_slot::normal)
		return (&normal_buffer[3 * index]);
	else if (slot == model_slot::color)
		return (&color_buffer[3 * index]);
	else
		throw (exception_enum());
}

void const			*model::pointer(const int &index, const model_slot &slot) const
{
	if (slot == model_slot::point)
		return (&point_buffer[3 * index]);
	else if (slot == model_slot::index)
		return (&index_buffer[3 * index]);
	else if (slot == model_slot::normal)
		return (&normal_buffer[3 * index]);
	else if (slot == model_slot::color)
		return (&color_buffer[3 * index]);
	else
		throw (exception_enum());
}