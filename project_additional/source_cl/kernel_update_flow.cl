static void			helper(
					global const float *const_flow,
					global const point2 *size,
                    global const float *terrain_data,
                    global float *water_data,
                    global float *flow_horizontal,
                    global float *flow_vertical,
                    flow_type flow,
                    const point2 *me,
                    const float *my_pressure,
                    point2 *neighbor)
{
	float			flow_value;
	float			neighbour_pressure;

	if (!IS_VALID(*neighbor))
		return ;

	neighbour_pressure = GET_TOTAL(*neighbor);
	flow_value = (neighbour_pressure - *my_pressure) * CONST_FLOW;
	ADD_FLOW(*me, flow, flow_value);
}

void kernel			update_flow(
					global const float *const_flow,
					global const float *const_depth,
					global const point2 *size,
					global const float *terrain_data,
					global float *water_data,
					global float *flow_horizontal,
					global float *flow_vertical)
{
	int				global_id = get_global_id(0);
	point2			task = {global_id % size->y, global_id / size->y};

	point2			right;
	point2			down;

	float 			task_pressure;
	float 			pressure_neighbour;
	float			flow_value;

	right = RIGHT(task);
	down = DOWN(task);

	task_pressure = GET_TOTAL(task);

	helper(
		const_flow, size, terrain_data, water_data, flow_horizontal, flow_vertical,
		flow_right, &task, &task_pressure, &right);
	helper(
		const_flow, size, terrain_data, water_data, flow_horizontal, flow_vertical,
		flow_down, &task, &task_pressure, &down);
}