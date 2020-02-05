#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::resize()
{
	const auto			start = (point3<double>)(point3<float>)(MOD1_TERRAIN_START);
	const auto			end = (point3<double>)(point3<float>)(MOD1_TERRAIN_END);
	auto				size = end - start;

	size.z = (diff_prepared.z / MOD1_MAX(diff_prepared.x, diff_prepared.y)) * MOD1_MAX(size.x, size.y);
	for (auto &point : data_raw)
	{
		point = start + point * size;
		for (int i = 0; i < 2; i++)
			point[i] = (int)point[i] / MOD1_TERRAIN_DELTA * MOD1_TERRAIN_DELTA;
	}
}