#include "mod1_terrain.h"

static int 				gcd(int a, int b)
{
	return (a ? gcd(b % a, a) : b);
}

void 					mod1_terrain::update_delta(const int &i, const int &j, const int &index)
{
	int 				temp_delta;

	temp_delta = abs(data_raw[i][index] - data_raw[j][index]);
	delta = gcd(delta, (int)temp_delta);
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
	return (count.x < MOD1_MAP_MIN_SIZE || count.y < MOD1_MAP_MIN_SIZE);
}

void 					mod1_terrain::optimize_delta()
{
	while (does_need_optimization(diff_raw, delta))
		if (!reduce(delta))
			break ;
}

void 					mod1_terrain::compute_delta()
{
	diff_raw = max_raw - min_raw;

	delta = 0;

	if (diff_raw == mod1_point3<int>())
	{
		delta = MOD1_MAP_DEFAULT_DELTA;
		diff_raw = MOD1_MAP_DEFAULT_SIZE;
	}
	else
		for (int i = 0; i < data_raw.size(); i++)
			for (int j = 0; j < data_raw.size(); j++)
			{
				if (j == i)
					continue ;
				update_delta(i, j, 0);
				update_delta(i, j, 1);
			}
}