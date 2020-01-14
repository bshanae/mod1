#include "mod1_water.h"

void					mod1_water::update_flow()
{
	mod1_point2<int>	iter;
	float 				height_me;
	float 				height_neighbour;

	for (iter.y = 0; iter.y < terrain->size().y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
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

//#define DEBUG

void					mod1_water::limit_flow()
{
	mod1_point2<int>	iter;
	float				flow[flow_end];
	float				sum;
	float				distribution[flow_end];
	float				depth;

	for (iter.y = 0; iter.y < terrain->size().y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
		{
			if ((depth = water_depth[iter]) < MOD1_WATER_EPSILON)
			{
				for (int i = flow_right; i < flow_end; i++)
					if (get_flow_safe(iter, (mod1_water_flow_type)i) < 0)
						set_flow_safe(iter, (mod1_water_flow_type)i, 0);
				continue ;
			}

			for (int i = flow_right; i < flow_end; i++)
			{
				flow[i] = get_flow_safe(iter, (mod1_water_flow_type)i);
				if (flow[i] > 0)
					flow[i] = 0;
			}

#ifdef DEBUG
			printf("\nDepth = %f\n", depth);
			printf("Flow : %f, %f, %f, %f\n", flow[0], flow[1], flow[2], flow[3]);
#endif

			if ((sum = -1 * (flow[0] + flow[1] + flow[2] + flow[3])) <= depth)
				continue;

			for (int i = flow_right; i < flow_end; i++)
				distribution[i] = flow[i] / sum;
			for (int i = flow_right; i < flow_end; i++)
				if (get_flow_safe(iter, (mod1_water_flow_type)i) < 0)
					set_flow_safe(iter, (mod1_water_flow_type) i, distribution[i] * depth);

#ifdef DEBUG
			for (int i = flow_right; i < flow_end; i++)
				flow[i] = get_flow_safe(iter, (mod1_water_flow_type) i);
			printf("Limited flow : %f, %f, %f, %f\n", flow[0], flow[1], flow[2], flow[3]);
#endif
		}
#ifdef DEBUG
	printf("\n");
#endif
}