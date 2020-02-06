#include "model.h"

using namespace		mod1_engine_gl;

bool				model::is_valid(const int &index, const model_slot &slot) const
{
	if (slot == model_slot::point)
		return (buffer_point.is_valid(3 * index));
	else if (slot == model_slot::index)
		return (buffer_index.is_valid(3 * index));
	else if (slot == model_slot::normal)
		return (buffer_normal.is_valid(3 * index));
	else if (slot == model_slot::color)
		return (buffer_color.is_valid(3 * index));
	else
		throw (exception_enum());
}
