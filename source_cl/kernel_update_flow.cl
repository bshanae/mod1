void kernel							update_flow(
									global const float *const_flow,
									global const float *const_depth,
									global const point2 *size,
									global const float *terrain_data,
									global float *water_data,
									global float *flow_horizontal,
									global float *flow_vertical)
{
	int								global_id = get_global_id(0);
	point2							task = {global_id % size->y, global_id / size->y};

	point2							right;
	point2							down;

	float 							height_me;
	float 							height_neighbour;
	float							flow_value;

	right = RIGHT(task);
	down = DOWN(task);

	height_me = GET_TOTAL(task);

	if (IS_VALID(right))
	{
		height_neighbour = GET_TOTAL(right);
		flow_value = (height_neighbour - height_me) * CONST_FLOW;
		ADD_FLOW(task, flow_right, flow_value);
	}

	if (IS_VALID(down))
	{
		height_neighbour = GET_TOTAL(down);
		flow_value = (height_neighbour - height_me) * CONST_FLOW;
		ADD_FLOW(task, flow_down, flow_value);
	}
}