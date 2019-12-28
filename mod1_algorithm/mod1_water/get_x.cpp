#include "mod1_water.h"

float				mod1_water::get_height(const mod1_point2<int> &iter)
{
	return (((float const *)terrain->get_ptr(iter, mod1_model_data::slot_point))[1]);
}

int					mod1_water::get_water(const mod1_point2<int> &iter)
{
	return (water_level[iter.x][iter.y]);
}

float				mod1_water::get_pressure(const mod1_point2<int> &iter)
{
	return (get_height(iter) + (float)get_water(iter) * water_drop_height);
}
