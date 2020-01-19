// /////////////////////////////////

//									GLOBAL

// /////////////////////////////////

#define NULL						0
#define EPSILON						0.01

#define IS_VALID(iter)				is_valid(size, &iter)

#define GET_TERRAIN(iter)			get_value_const(terrain_data, size, &iter)
#define GET_WATER(iter)				get_value(water_data, size, &iter)
#define GET_TOTAL(iter)				GET_TERRAIN(iter) + GET_WATER(iter)

typedef enum
{
	flow_right = 0,
	flow_up,
	flow_left,
	flow_down,
	flow_end
}									flow_type;

#define GET_FLOW(iter, flow)		get_flow(flow_horizontal, flow_vertical, size, &iter, flow)
#define SET_FLOW(iter, flow, value)	set_flow(flow_horizontal, flow_vertical, size, &iter, flow, value);

#define SET(data, iter, value)		set_value(data, size, &iter, value);

#define RIGHT(point)				(point2){(point).x + 1, (point).y + 0}
#define UP(point)					(point2){(point).x + 0, (point).y - 1}
#define LEFT(point)					(point2){(point).x - 1, (point).y + 0}
#define DOWN(point)					(point2){(point).x + 0, (point).y + 1}

#define CONST_FLOW					*const_flow

typedef struct
{
	int								x;
	int								y;
}									point2;

// /////////////////////////////////

//									DATA

// /////////////////////////////////

static int							is_valid(
									global const point2 *size,
									point2 *iter)
{
	if (iter->x < 0 || iter->x >= size->x)
		return (0);
	if (iter->y < 0 || iter->y >= size->y)
    	return (0);
    return (1);
}

static int							get_index(
									global const point2 *size,
                   		 			point2 *iter)
{
	return (size->x * iter->y + iter->x);
}

static global float					*get_ptr(
									global float *data,
									global const point2 *size,
									point2 *iter)
{
	 if (!is_valid(size, iter))
	 	return (NULL);
	 return (data + get_index(size, iter));
}

static global const float			*get_ptr_const(
									global const float *data,
									global const point2 *size,
									point2 *iter)
{
	 if (!is_valid(size, iter))
	 	return (NULL);
	 return (data + get_index(size, iter));
}

static float						get_value(
									global float *data,
									global const point2 *size,
									point2 *iter)
{
	return (*get_ptr(data, size, iter));
}

static float						get_value_const(
									global const float *data,
									global const point2 *size,
									point2 *iter)
{
	return (*get_ptr_const(data, size, iter));
}

static float						get_value_safe(
									global float *data,
									global const point2 *size,
									point2 *iter)
{
	if (is_valid(size, iter))
		return (*get_ptr(data, size, iter));
	else
		return (0);
}

static float						get_flow(
									global float *horizontal,
									global float *vertical,
                                	global const point2 *size,
                                	point2 *iter,
                                	flow_type flow)
{
	point2							iter_local;

	if (flow == flow_right)
	{
		iter_local = *iter;
		return (get_value_safe(horizontal, size, &iter_local));
	}
	else if (flow == flow_up)
	{
		iter_local = UP(*iter);
		return (-1 * get_value_safe(vertical, size, &iter_local));
	}
	else if (flow == flow_left)
    {
    	iter_local = LEFT(*iter);
    	return (-1 * get_value_safe(horizontal, size, &iter_local));
    }
    else if (flow == flow_down)
    {
    	iter_local = *iter;
    	return (get_value_safe(vertical, size, &iter_local));
    }
    else
    	return (0);
}

static void							set_value(
									global float *data,
									global const point2 *size,
									point2 *iter,
									float value)
{
	*get_ptr(data, size, iter) = value;
}

static int							set_value_safe(
									global float *data,
									global const point2 *size,
									point2 *iter,
									float value)
{
	if (is_valid(size, iter))
	{
		set_value(data, size, iter, value);
		return (1);
	}
	return (0);
}

static void							set_flow(
									global float *horizontal,
									global float *vertical,
                                	global const point2 *size,
                                	point2 *iter,
                                	flow_type flow,
                                	float value)
{
	point2							iter_local;

	if (flow == flow_right)
	{
		iter_local = *iter;
		set_value_safe(horizontal, size, &iter_local, value);
	}
	else if (flow == flow_up)
	{
		iter_local = UP(*iter);
		set_value_safe(vertical, size, &iter_local, -1 * value);
	}
	else if (flow == flow_left)
    {
    	iter_local = LEFT(*iter);
    	set_value_safe(horizontal, size, &iter_local, -1 * value);
    }
    else if (flow == flow_down)
    {
    	iter_local = *iter;
    	set_value_safe(vertical, size, &iter_local, value);
    }
}

// /////////////////////////////////

//									KERNEL

// /////////////////////////////////

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
		SET_FLOW(task, flow_right, flow_value)
	}

	if (IS_VALID(down))
	{
		height_neighbour = GET_TOTAL(down);
		flow_value = (height_neighbour - height_me) * CONST_FLOW;
		SET_FLOW(task, flow_down, flow_value)
	}
}

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
        	SET_FLOW(task, i, water * distribution[i])
}

void kernel							debug(
									global const float *const_flow,
									global const float *const_depth,
									global const point2 *size,
									global const float *terrain_data,
									global float *water_data,
									global float *flow_horizontal,
									global float *flow_vertical)
{
	point2							iter;

	for (iter.y = 0; iter.y < size->y; iter.y++)
	{
		for (iter.x = 0; iter.x < size->x; iter.x++)
    	{
    		if (iter.x)
    			printf(" : ");
    		printf("[%+7.2f] : %+7.2f ",
				GET_WATER(iter),
    			GET_FLOW(iter, flow_right));
    	}
    	printf("\n");

    	for (iter.x = 0; iter.x < size->x; iter.x++)
    	{
    		if (iter.x)
    			printf("             ");
    		printf("    ..    ");
    	}
    	printf("\n");

    	for (iter.x = 0; iter.x < size->x; iter.x++)
    	{
    		if (iter.x)
    			printf("             ");
    		printf(" %+7.2f  ",
    			GET_FLOW(iter, flow_down));
    	}
    	printf("\n");

    	for (iter.x = 0; iter.x < size->x; iter.x++)
    	{
    		if (iter.x)
                			printf("             ");
    		printf("    ..    ");
    	}
    	printf("\n");
	}
	printf("\n");
}