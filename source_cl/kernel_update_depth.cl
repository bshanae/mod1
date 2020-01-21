void kernel							update_depth(
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

	float							total_flow = 0;

	for (int i = 0; i < flow_end; i++)
		total_flow += GET_FLOW(task, i);

	ADD_WATER_DIFFUSED(task, total_flow * CONST_DEPTH, 0.5)
}