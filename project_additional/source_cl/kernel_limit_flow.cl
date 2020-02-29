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

	float							water_available = (GET_WATER(task)) / CONST_DEPTH;

	float							flow[4];
	int								edit[4];
	float							distribution[4];

	//								sum : sum of all flows
	//								sum_edit : sum of outcoming flows
	//								limit : limit amount of outcoming flows

	float							sum;
	float							sum_edit;
	float							limit;

	for (int i = 0; i < flow_end; i++)
	{
		flow[i] = GET_FLOW(task, i);
		if (MOD(flow[i]) < 0.5)
		{
			SET_FLOW(task, i, 0);
			flow[i] = 0;
		}
		edit[i] = flow[i] < 0;
	}

	sum = 0;
	sum_edit = 0;
	for (int i = 0; i < flow_end; i++)
    {
    	sum += flow[i];
    	if (edit[i])
    		sum_edit += flow[i];
    }

	if (-1 * sum_edit < water_available)
		return ;

	limit = water_available;

    for (int i = 0; i < flow_end; i++)
		distribution[i] = edit[i] ? flow[i] / sum_edit : 0;

	for (int i = 0; i < flow_end; i++)
        if (edit[i])
        	SET_FLOW(task, i, -1 * limit * distribution[i]);
}