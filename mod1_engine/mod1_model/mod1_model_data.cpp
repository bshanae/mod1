#include "mod1_model_data.h"

const char *		mod1_model_data::exception_unknown_slot::what() const throw()
{
	return ("Mod1 Model Data : Unknown slot");
}

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
