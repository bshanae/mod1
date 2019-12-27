#include "mod1_terrain.h"

void					mod1_terrain::prepare()
{
	compute_delta();
	optimize_delta();

	min_i = min_raw;
	max_i = max_raw;

	mod1_point2<int>	test;

	for (auto const &iter : data_raw)
	{
		test = mod1_point2<int>(iter.x - iter.z, iter.y - iter.z);
		min_i = mod1_point2<int>::min(min_i, test);
		test = mod1_point2<int>(iter.x + iter.z, iter.y + iter.z);
		max_i = mod1_point2<int>::max(max_i, test);
	}

	mod1_point2<int>	indent = (max_i - min_i) * MOD1_MAP_INDENT;

	min_i -= indent;
	max_i += indent;

	min_i = (min_i / delta_i - mod1_point2<int>(1)) * delta_i;
	max_i = (max_i / delta_i + mod1_point2<int>(1)) * delta_i;

	min = min_i;
	max = max_i;
}