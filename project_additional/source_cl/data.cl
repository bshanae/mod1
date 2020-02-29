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