#include "mod1_map.h"

static int 				gcd(int a, int b)
{
	return (a ? gcd(b % a, a) : b);
}

void 					mod1_map::model_update_delta(const int &i, const int &j, const int &index)
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
	mod1_point2<int>	count;

	count = diff / delta;
	return (count.x < MOD1_MAP_MIN_COUNT || count.y < MOD1_MAP_MIN_COUNT);
}

void 					mod1_map::model_optimize_delta(const mod1_point3<int> &diff)
{
	while (does_need_optimization(diff, model_delta))
		if (!reduce(model_delta))
			break ;
}