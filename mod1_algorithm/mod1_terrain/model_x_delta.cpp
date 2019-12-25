#include "mod1_terrain.h"

static int 				gcd(int a, int b)
{
	return (a ? gcd(b % a, a) : b);
}

void 					mod1_terrain::model_update_delta(const int &i, const int &j, const int &index)
{
	int 				temp_delta;

	temp_delta = abs(source_data[i][index] - source_data[j][index]);
	model_delta = gcd(model_delta, (int)temp_delta);
}

static bool				reduce(int &value)
{
	for (int temp = 2; temp <= value; temp++)
		if (value % temp == 0)
		{
			value /= temp;
			return (true);
		}
	return (false);
}

static bool				does_need_optimization(const mod1_point3<int> &diff, const int &delta)
{
	mod1_point3<int>	count;

	count = diff / delta;
	return (count.x < MOD1_MAP_MIN_COUNT || count.y < MOD1_MAP_MIN_COUNT);
}

void 					mod1_terrain::model_optimize_delta()
{
	while (does_need_optimization(source_diff, model_delta))
		if (!reduce(model_delta))
			break ;
}

void 					mod1_terrain::model_compute_delta()
{
	source_diff = source_max - source_min;

	model_delta = 0;

	if (source_diff == mod1_point3<int>())
	{
		model_delta = MOD1_MAP_DEF_DELTA;
		source_diff = MOD1_MAP_DEF_SIZE;
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
}