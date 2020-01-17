//							GLOBAL

#define NULL				0

typedef struct
{
	int						x;
	int						y;
}							point2;

//							DATA

static int					is_valid(
							global const point2 *size,
							point2 *iter)
{
	if (iter->x < 0 || iter->x >= size->x)
		return (0);
	if (iter->y < 0 || iter->y >= size->y)
    	return (0);
    return (1);
}

static int					get_index(
							global const point2 *size,
                   		 	point2 *iter)
{
	return (size->x * iter->y + iter->x);
}

static global float			*get_ptr(
							global float *data,
							global const point2 *size,
							point2 *iter)
{
	 if (!is_valid(size, iter))
	 	return (NULL);
	 return (data + get_index(size, iter));
}

static global const float	*get_ptr_const(
							global const float *data,
							global const point2 *size,
							point2 *iter)
{
	 if (!is_valid(size, iter))
	 	return (NULL);
	 return (data + get_index(size, iter));
}

//							KERNEL

void kernel					update_flow(
							global const float *terrain_data,
							global const point2 *terrain_size)
/*
							global const point2 *water_size,
							global float *water_data,
							global float *flow_horizontal,
							global float *flow_vertical)
*/
{
	point2					iter;
	global const float		*ptr;

	printf("Device : \n");
	for (iter.y = 0; iter.y < terrain_size->y; iter.y++)
    {
    	for (iter.x = 0; iter.x < terrain_size->x; iter.x++)
    	{
    		ptr = get_ptr_const(terrain_data, terrain_size, &iter);
    		if (!ptr)
    			printf("null ");
    		else
    			printf("%5.1f ", ptr[0]);
    	}
    	printf("\n");
    }
    printf("\n");
}