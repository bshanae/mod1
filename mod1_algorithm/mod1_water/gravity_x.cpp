#include "mod1_water.h"

#include <iostream>

void					mod1_water::update_flow()
{
	mod1_point2<int>	iter;
	float 				height_me;
	float 				height_neighbour;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			height_me = get_total_height(iter);
			try
			{
				height_neighbour = get_total_height(iter + MOD1_WATER_RIGHT);
				flow_horizontal[iter] += (height_neighbour - height_me) * flow_constant;
			}
			catch (...)
			{}

			try
			{
				height_neighbour = get_total_height(iter + MOD1_WATER_DOWN);
				flow_vertical[iter] += (height_neighbour - height_me) * flow_constant;
			}
			catch (...)
			{}
		}
}

void					mod1_water::update_water_depth()
{
	mod1_point2<int>	iter;
	float 				total_flow;
	float 				total_temp;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			total_flow = 0;
			for (int i = flow_right; i <= flow_down; i++)
				try
				{
					total_temp = get_flow(iter, (mod1_water_flow_type)i);
					total_flow += total_temp;
				}
				catch (...)
				{}
			water_depth[iter.x][iter.y] += total_flow * water_depth_constant;
		}
}

void					mod1_water::gravity()
{
	update_flow();
	update_water_depth();
	update_height();

	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
	{
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
			printf("(%f, %f) ", flow_horizontal[iter], flow_vertical[iter]);
		printf("\n");
	}
	printf("\n");

}