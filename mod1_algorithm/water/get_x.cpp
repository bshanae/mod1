#include "water.h"

using namespace		mod1_algorithm;

float				water::get_terrain_height(const point2<int> &iter)
{
	return (terrain->read_height(iter));
}

float				water::get_flow(const point2<int> &iter, const mod1_water_flow_type &type)
{
	if (type == flow_right)
		return (flow_horizontal[iter.x][iter.y]);
	else if (type == flow_up)
		return (-1 * flow_vertical[iter.x][iter.y - 1]);
	else if (type == flow_left)
		return (-1 * flow_horizontal[iter.x - 1][iter.y]);
	else if (type == flow_down)
		return (flow_vertical[iter.x][iter.y]);
	throw (exception_unknown_flow_type());
}

float				water::get_flow_safe(const point2<int> &iter, const mod1_water_flow_type &type)
{
	try
	{
		return (get_flow(iter, type));
	}
	catch (buffer<float>::exception_index &exception)
	{}
	catch (buffer2<float>::exception_index &exception)
	{}
	return (0);
}

float				water::get_total_height(const point2<int> &iter)
{
	return (get_terrain_height(iter) + water_depth[iter]);
}
