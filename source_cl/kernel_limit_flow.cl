void kernel							limit_flow(
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

	float							water = GET_WATER(task);

	float							flow[4];
	int								useful[4];
	float							distribution[4];
	float							sum;

	for (int i = 0; i < flow_end; i++)
	{
		flow[i] = GET_FLOW(task, i);
		useful[i] = flow[i] < -EPSILON;
	}

	sum = 0;
	for (int i = 0; i < flow_end; i++)
    	if (useful[i])
    		sum += flow[i];

    for (int i = 0; i < flow_end; i++)
		distribution[i] = useful[i] ? flow[i] / sum : 0;

	for (int i = 0; i < flow_end; i++)
        if (useful[i])
        	SET_FLOW(task, i, -1 * water * distribution[i])
}