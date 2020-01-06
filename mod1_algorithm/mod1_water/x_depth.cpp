#include "mod1_water.h"

void					mod1_water::update_depth()
{
	mod1_point2<int>	iter;
	float 				total_flow;
	float 				total_temp;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			total_flow = 0;
			for (int i = flow_right; i <= flow_down; i++)
			{
				total_temp = get_flow_safe(iter, (mod1_water_flow_type)i);
				total_flow += total_temp;
			}
			water_depth[iter] += total_flow * water_depth_constant;
		}
}

void					mod1_water::diffuse_depth()
{
	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
			water_depth[iter] = (water_depth[iter] + water_depth_copy[iter]) / 2;
}