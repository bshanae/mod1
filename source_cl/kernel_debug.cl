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
				GET_WATER_BALANCED(iter),
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