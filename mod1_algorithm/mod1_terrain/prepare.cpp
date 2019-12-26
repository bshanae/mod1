#include "mod1_terrain.h"

void					mod1_terrain::prepare()
{
	compute_delta();
	optimize_delta();
	printf("model delta = %d\n", delta);

	min = min_raw;
	max = max_raw;

	mod1_point2<int>	test;

	for (auto const &iter : data_raw)
	{
		test = mod1_point2<int>(iter.x - iter.z, iter.y - iter.z);
		min = mod1_point2<int>::min(min, test);
		test = mod1_point2<int>(iter.x + iter.z, iter.y + iter.z);
		max = mod1_point2<int>::max(max, test);
	}

	mod1_point2<int>	indent = (max - min) * MOD1_MAP_INDENT;
	min -= indent;
	max += indent;

	min = (min / delta - mod1_point2<int>(1)) * delta;
	max = (max / delta + mod1_point2<int>(1)) * delta;

	size = (max - min) / delta + mod1_point2<int>(1);

	printf("Model min = %d, %d\n", min.x, min.y);
	printf("Model max = %d, %d\n", max.x, max.y);
	printf("Model size = %d, %d\n", size.x, size.y);
}