#include "model.h"

using namespace		mod1_engine_gl;

void 				*model::pointer(const int &index, const model_slot &slot)
{
	if (slot == model_slot::point)
		return (&buffer_point[3 * index]);
	else if (slot == model_slot::index)
		return (&buffer_index[3 * index]);
	else if (slot == model_slot::normal)
		return (&buffer_normal[3 * index]);
	else if (slot == model_slot::color)
		return (&buffer_color[3 * index]);
	else
		throw (exception_enum());
}

void const			*model::pointer(const int &index, const model_slot &slot) const
{
	if (slot == model_slot::point)
		return (&buffer_point[3 * index]);
	else if (slot == model_slot::index)
		return (&buffer_index[3 * index]);
	else if (slot == model_slot::normal)
		return (&buffer_normal[3 * index]);
	else if (slot == model_slot::color)
		return (&buffer_color[3 * index]);
	else
		throw (exception_enum());
}