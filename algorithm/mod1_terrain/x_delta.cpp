#include "mod1_terrain.h"

static int 				gcd(int a, int b)
{
	return (a ? gcd(b % a, a) : b);
}

void 					mod1_terrain::update_delta(const int &i, const int &j, const int &index)
{
	int 				temp_delta;

	temp_delta = abs(data_raw[i][index] - data_raw[j][index]);
	delta_i = gcd(delta_i, (int)temp_delta);
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

static bool				does_need_optimization(const point3<int> &diff, const int &delta_i)
{
	point3<int>	count;

	count = diff / delta_i;
	return (count.x < MOD1_TERRAIN_MIN_SIZE || count.y < MOD1_TERRAIN_MIN_SIZE);
}

void 					mod1_terrain::optimize_delta()
{
	while (does_need_optimization(diff_raw, delta_i))
		if (!reduce(delta_i))
			break ;
}

void 					mod1_terrain::compute_delta()
{
	diff_raw = max_raw - min_raw;

	if (diff_raw == point3<int>())
	{
		case_one_point = true;
		delta_i = MOD1_TERRAIN_DEFAULT_DELTA;
		diff_raw = MOD1_TERRAIN_DEFAULT_SIZE;
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