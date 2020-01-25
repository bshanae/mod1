#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::normalize()
{
	point3<double>		min = min_raw;
	point3<double>		max = max_raw;
	point3<double>		temp;
	point3<double>		diff;

	for (const auto &point : data_raw)
	{
		temp = point3<double>(
			point.x - fabs(point.z),
			point.y - fabs(point.z),
			point.z);
		min = point3<double>::min(min, temp);
	}

	for (const auto &point : data_raw)
	{
		temp = point3<double>(
			point.x + fabs(point.z),
			point.y + fabs(point.z),
			point.z);
		max = point3<double>::max(max, temp);
	}

	diff = max - min;

	min = min - diff * MOD1_TERRAIN_INDENT;
	max = max + diff * MOD1_TERRAIN_INDENT;

	min.z = min_raw.z;
	max.z = max_raw.z;

	diff = max - min;

	for (auto &point : data_raw)
	{
		point[0] = (point[0] - min[0]) / diff[0];
		point[1] = (point[1] - min[1]) / diff[1];
		point[2] = point[2] / diff[2];
	}
}