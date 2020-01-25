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
		temp = point3<double>(point.x - point.z, point.y - point.z, point.z);
		min = point3<double>::min(min, temp);
	}

	for (const auto &point : data_raw)
	{
		temp = point3<double>(point.x + point.z, point.y + point.z, point.z);
		max = point3<double>::max(max, temp);
	}

	diff = max - min;

	min = min - diff * MOD1_TERRAIN_INDENT;
	max = max + diff * MOD1_TERRAIN_INDENT;

	min.z = min_raw.z;
	max.z = max_raw.z;

	diff = max - min;

	std::cout << "min = " << min << std::endl;
	std::cout << "max = " << max << std::endl;
	std::cout << "diff = " << diff << std::endl;
	std::cout << std::endl;

	for (auto &point : data_raw)
	{
		point = (point - min) / diff;
		std::cout << "Normalized : " << point << std::endl;
	}

	std::cout << std::endl;
}