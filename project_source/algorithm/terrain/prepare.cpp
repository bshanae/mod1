#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::prepare()
{
	min_prepared = min_raw;
	max_prepared = max_raw;

	point3<double>		temp;

	for (const auto &point : data_raw)
	{
		temp = point3<double>(
			point.x - fabs(point.z),
			point.y - fabs(point.z),
			point.z);
		min_prepared = point3<double>::min(min_prepared, temp);
	}

	for (const auto &point : data_raw)
	{
		temp = point3<double>(
			point.x + fabs(point.z),
			point.y + fabs(point.z),
			point.z);
		max_prepared = point3<double>::max(max_prepared, temp);
	}

	diff_prepared = max_prepared - min_prepared;

	min_prepared = min_prepared - diff_prepared * MOD1_TERRAIN_INDENT;
	max_prepared = max_prepared + diff_prepared * MOD1_TERRAIN_INDENT;

	min_prepared.z = min_raw.z;
	max_prepared.z = max_raw.z;

	diff_prepared = max_prepared - min_prepared;
}