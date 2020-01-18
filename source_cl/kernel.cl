//								GLOBAL

#define NULL					0

#define IS_VALID(iter)			is_valid(size, &iter)

#define GET_TERRAIN(iter)		get_value_const(terrain_data, size, &iter)
#define GET_WATER(iter)			get_value(water_data, size, &iter)
#define GET_TOTAL(iter)			GET_TERRAIN(iter) + GET_WATER(iter)

typedef enum
{
	right,
	down
}								flow;

#define GET_FLOW_DATA(flow)		((flow == right) ? flow_horizontal : (flow == down ? flow_vertical : NULL))
#define GET_FLOW(flow, iter)	get_value(GET_FLOW_DATA(flow), size, &iter)

#define SET(data, iter, value)	set_value(data, size, &iter, value);

#define RIGHT(point)			(point2){point.x + 1, point.y}
#define DOWN(point)				(point2){point.x, point.y + 1}

#define CONST_FLOW				*const_flow

typedef struct
{
	int							x;
	int							y;
}								point2;

//								DATA

static int						is_valid(
								global const point2 *size,
								point2 *iter)
{
	if (iter->x < 0 || iter->x >= size->x)
		return (0);
	if (iter->y < 0 || iter->y >= size->y)
    	return (0);
    return (1);
}

static int						get_index(
								global const point2 *size,
                   		 		point2 *iter)
{
	return (size->x * iter->y + iter->x);
}

static global float				*get_ptr(
								global float *data,
								global const point2 *size,
								point2 *iter)
{
	 if (!is_valid(size, iter))
	 	return (NULL);
	 return (data + get_index(size, iter));
}

static global const float		*get_ptr_const(
								global const float *data,
								global const point2 *size,
								point2 *iter)
{
	 if (!is_valid(size, iter))
	 	return (NULL);
	 return (data + get_index(size, iter));
}

static float					get_value(
								global float *data,
								global const point2 *size,
								point2 *iter)
{
	return (*get_ptr(data, size, iter));
}

static float					get_value_const(
								global const float *data,
								global const point2 *size,
								point2 *iter)
{
	return (*get_ptr(data, size, iter));
}

static float					set_value(
								global float *data,
								global const point2 *size,
								point2 *iter,
								float value)
{
	*get_ptr(data, size, iter) = value;
}

//								KERNEL

void kernel						update_flow(
								global const float *const_flow,
								global const float *const_depth,
								global const point2 *size,
								global const float *terrain_data,
								global float *water_data,
								global float *flow_horizontal,
								global float *flow_vertical)
{
	point2						iter;
	point2						right;
	point2						down;

	float 						height_me;
	float 						height_neighbour;
	float						flow_value;

	for (iter.y = 0; iter.y < size->y; iter.y++)
		for (iter.x = 0; iter.x < size->x; iter.x++)
		{
			right = RIGHT(iter);
			down = DOWN(iter);

			height_me = GET_TOTAL(iter);

			if (IS_VALID(right))
			{
				height_neighbour = GET_TOTAL(right);
				flow_value = (height_neighbour - height_me) * CONST_FLOW;
				SET(flow_horizontal, iter, flow_value)
			}

			if (IS_VALID(down))
			{
				height_neighbour = GET_TOTAL(down);
				flow_value = (height_neighbour - height_me) * CONST_FLOW;
				SET(flow_vertical, iter, flow_value)
			}
		}
}

void kernel						debug(
								global const float *const_flow,
								global const float *const_depth,
								global const point2 *size,
								global const float *terrain_data,
								global float *water_data,
								global float *flow_horizontal,
								global float *flow_vertical)
{
	point2						iter;

	for (iter.y = 0; iter.y < size->y; iter.y++)
	{
		for (iter.x = 0; iter.x < size->x; iter.x++)
    	{
    		if (iter.x)
    			printf(" : ");
    		printf("[%+7.2f] : %+7.2f ",
				GET_WATER(iter),
    			GET_FLOW(right, iter));
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
    			GET_FLOW(down, iter));
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