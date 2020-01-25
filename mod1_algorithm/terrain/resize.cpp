#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::resize()
{
	for (auto &point : data_raw)
	{
		point *= (point3<double>)MOD1_TERRAIN_SIZE;
		for (int i = 0; i < 2; i++)
			point[i] = (int)point[i] / MOD1_TERRAIN_DELTA * MOD1_TERRAIN_DELTA;
		std::cout << "Resized : " << point << std::endl;
	}
	std::cout << std::endl;
}