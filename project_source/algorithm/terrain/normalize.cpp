#include "terrain.h"

using namespace			mod1_algorithm;

void					terrain::normalize()
{
	for (auto &point : data_raw)
	{
		point[0] = (point[0] - min_prepared[0]) / diff_prepared[0];
		point[1] = (point[1] - min_prepared[1]) / diff_prepared[1];
		point[2] = point[2] / diff_prepared[2];
	}
}