#include "water.h"

using namespace			mod1_algorithm;

void					water::update_depth()
{
	point2<int>			iter;
	float 				total_flow;
	float 				total_temp;

	for (iter.y = 0; iter.y < terrain->size().y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
		{
			total_flow = 0;
			for (int i = flow_right; i < flow_end; i++)
			{
				total_temp = get_flow_safe(iter, (mod1_water_flow_type)i);
				total_flow += total_temp;
			}
			water_depth[iter] += total_flow * water_depth_constant;
		}
}

void					water::diffuse_depth()
{
	point2<int>			iter;

	for (iter.y = 0; iter.y < terrain->size().y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
			water_depth[iter] = (water_depth[iter] + water_depth_copy[iter]) / 2;
}