#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::prepare()
{
	compute_delta();

	if (case_one_point)
	{
		min_i = data_raw[0] - diff_raw / 2;
		max_i = data_raw[0] + diff_raw / 2;
		return ;
	}

	optimize_delta();

	min_i = min_raw;
	max_i = max_raw;

	point2<int>			test;

	for (auto const &iter : data_raw)
	{
		test = point2<int>(iter.x - iter.z, iter.y - iter.z);
		min_i = point2<int>::min(min_i, test);
		test = point2<int>(iter.x + iter.z, iter.y + iter.z);
		max_i = point2<int>::max(max_i, test);
	}

	point2<int> indent = (max_i - min_i) * MOD1_TERRAIN_INDENT;

	min_i -= indent;
	max_i += indent;

	min_i = (min_i / delta_i - point2<int>(1)) * delta_i;
	max_i = (max_i / delta_i + point2<int>(1)) * delta_i;
}