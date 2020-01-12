#include "model_data.h"

using namespace		mod1_engine;

MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(model_data, exception_unknown_slot)

void 				*model_data::get_ptr(const int &index, const slot_type &slot)
{
	if (slot == slot_point)
		return (&point_buffer[3 * index]);
	else if (slot == slot_index)
		return (&index_buffer[3 * index]);
	else if (slot == slot_normal)
		return (&normal_buffer[3 * index]);
	else if (slot == slot_color)
		return (&color_buffer[3 * index]);
	else
		throw (exception_unknown_slot());
}

void const			*model_data::get_ptr(const int &index, const slot_type &slot) const
{
	if (slot == slot_point)
		return (&point_buffer[3 * index]);
	else if (slot == slot_index)
		return (&index_buffer[3 * index]);
	else if (slot == slot_normal)
		return (&normal_buffer[3 * index]);
	else if (slot == slot_color)
		return (&color_buffer[3 * index]);
	else
		throw (exception_unknown_slot());
}

bool				model_data::is_valid(const int &index, const slot_type &slot) const
{
	if (slot == slot_point)
		return (point_buffer.is_valid(3 * index));
	else if (slot == slot_index)
		return (index_buffer.is_valid(3 * index));
	else if (slot == slot_normal)
		return (normal_buffer.is_valid(3 * index));
	else if (slot == slot_color)
		return (color_buffer.is_valid(3 * index));
	else
		throw (exception_unknown_slot());
}