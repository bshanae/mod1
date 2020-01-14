#include "water.h"

using namespace		mod1_algorithm;

void				water::set_flow(const point2<int> &iter, const mod1_water_flow_type &type, const float &value)
{
	if (type == flow_right)
		flow_horizontal[iter.x][iter.y] = value;
	else if (type == flow_up)
		flow_vertical[iter.x][iter.y - 1] = -1 * value;
	else if (type == flow_left)
		flow_horizontal[iter.x - 1][iter.y] = -1 * value;
	else if (type == flow_down)
		flow_vertical[iter.x][iter.y] = value;
	else
		throw (exception_unknown_flow_type());
}

bool				water::set_flow_safe(const point2<int> &iter, const mod1_water_flow_type &type, const float &value)
{
	try
	{
		set_flow(iter, type, value);
		return (true);
	}
	catch (buffer<float>::exception_index &exception)
	{}
	catch (buffer2<float>::exception_index &exception)
	{}
	return (false);
}
