#include "mod1_water.h"

void					mod1_water::update_flow()
{
	mod1_point2<int>	iter;
	float 				height_me;
	float 				height_neighbour;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{

			height_me = get_total_height(iter);

			if (terrain->is_valid(iter + MOD1_WATER_RIGHT, mod1_model_data::slot_point))
			{
				height_neighbour = get_total_height(iter + MOD1_WATER_RIGHT);
				flow_horizontal[iter] += (height_neighbour - height_me) * flow_constant;
			}

			if (terrain->is_valid(iter + MOD1_WATER_DOWN, mod1_model_data::slot_point))
			{
				height_neighbour = get_total_height(iter + MOD1_WATER_DOWN);
				flow_vertical[iter] += (height_neighbour - height_me) * flow_constant;
			}
		}
}

void					mod1_water::limit_flow()
{
	mod1_point2<int>	iter;
	float 				flow_right;
	float 				flow_down;
	float 				height_neighbour;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{

			flow_right = get_total_height(iter);

			if (terrain->is_valid(iter + MOD1_WATER_RIGHT, mod1_model_data::slot_point))
			{
				height_neighbour = get_total_height(iter + MOD1_WATER_RIGHT);
				flow_horizontal[iter] += (height_neighbour - flow_right) * flow_constant;
			}

			if (terrain->is_valid(iter + MOD1_WATER_DOWN, mod1_model_data::slot_point))
			{
				height_neighbour = get_total_height(iter + MOD1_WATER_DOWN);
				flow_vertical[iter] += (height_neighbour - flow_right) * flow_constant;
			}
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
			water_depth[iter] += total_flow * water_depth_constant;
		}
}

void					mod1_water::gravity()
{
	update_flow();
	update_water_depth();
	update_height();

# define RED			"\033[0;31m"
# define BLACK			"\033[0m"
#define	DEBUG

#ifdef DEBUG
	mod1_point2<int>	iter;
	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
	{
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			if (iter.x)
				printf(":");
			printf("[%+7.2f]:%s%+7.2f%s",
				water_depth[iter],
				RED, get_flow(iter, mod1_water::flow_right), BLACK);
		}
		printf("\n");
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			if (iter.x)
				printf("        ");
			printf("    ..    ");
		}
		printf("\n");
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			if (iter.x)
				printf("         ");
			printf("%s %+7.2f %s", RED, get_flow(iter, mod1_water::flow_down), BLACK);
		}
		printf("\n");
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			if (iter.x)
				printf("        ");
			printf("    ..    ");
		}
		printf("\n");
	}
	printf("\n");
#endif
}