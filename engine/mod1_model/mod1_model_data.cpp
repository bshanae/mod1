#include "mod1_model_data.h"

MOD1_GENERATE_EXCEPTION_IMPLEMENTATION(mod1_model_data, exception_unknown_slot)

void 				*mod1_model_data::get_ptr(const int &index, const slot_type &slot)
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

void const			*mod1_model_data::get_ptr(const int &index, const slot_type &slot) const
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

bool				mod1_model_data::is_valid(const int &index, const slot_type &slot) const
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