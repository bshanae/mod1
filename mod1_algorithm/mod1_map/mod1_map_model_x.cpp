#include "mod1_map.h"

static int 					gcd(int a, int b)
{
	return (a ? gcd(b % a, a) : b);
}

void 						mod1_map::model_update_delta(const int &i, const int &j, const int &index)
{
	int 					temp_delta;

	temp_delta = abs(source_data[i][index] - source_data[j][index]);
	model_delta = gcd(model_delta, (int)temp_delta);
}

static bool					reduce(int &value)
{
	for (int temp = 2; temp < value; temp++)
		if (value % temp == 0)
		{
			value /= temp;
			return (true);
		}
	return (false);
}

static bool					does_need_optimization(const mod1_point3<int> &size, const int &delta)
{
	mod1_point2<int>		count;

	count = size / delta;
	return (count.x < MOD1_MAP_MIN_COUNT || count.y < MOD1_MAP_MIN_COUNT);
}

void 						mod1_map::model_optimize_delta(const mod1_point3<int> &size)
{
	while (does_need_optimization(size, model_delta))
		if (!reduce(model_delta))
			break ;
}

void						mod1_map::model_prepare()
{
	mod1_point3<int>		model_size = source_max - source_min;

	model_delta = 0;

	if (model_size == mod1_point3<int>())
	{
		model_delta = MOD1_MAP_DEF_DELTA;
		model_size = MOD1_MAP_DEF_SIZE;
	}
	else
		for (int i = 0; i < source_data.size(); i++)
			for (int j = 0; j < source_data.size(); j++)
			{
				if (j == i)
					continue ;
				model_update_delta(i, j, 0);
				model_update_delta(i, j, 1);
			}

	model_optimize_delta(model_size);

	printf("model delta = %d\n", model_delta);

	model_min = source_min - model_size * MOD1_MAP_INDENT;
	model_max = source_max + model_size * MOD1_MAP_INDENT;

	model_min = (model_min / model_delta - mod1_point2<int>(1)) * model_delta;
	model_max = (model_max / model_delta + mod1_point2<int>(1)) * model_delta;

	printf("model min = %d, %d\n", model_min.x, model_min.y);
	printf("model max = %d, %d\n", model_max.x, model_max.y);
}

void						mod1_map::model_build()
{
	model_prepare();
}
