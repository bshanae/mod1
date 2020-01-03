#include "mod1_water.h"

float				mod1_water::get_terrain_height(const mod1_point2<int> &iter)
{
	return (((float const *)terrain->get_ptr(iter, mod1_model_data::slot_point))[1]);
}

float				mod1_water::get_flow(const mod1_point2<int> &iter, const mod1_water_flow_type &type)
{
	if (type == flow_right)
		return (flow_horizontal[iter.x][iter.y]);
	else if (type == flow_up)
		return (flow_vertical[iter.x][iter.y - 1]);
	else if (type == flow_left)
		return (flow_horizontal[iter.x - 1][iter.y]);
	else if (type == flow_down)
		return (flow_vertical[iter.x][iter.y]);
	throw (exception_unknown_flow_type());
}

float				mod1_water::get_total_height(const mod1_point2<int> &iter)
{
	return (get_terrain_height(iter) + water_depth[iter]);
}
