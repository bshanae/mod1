#include "terrain.h"

using namespace			mod1_algorithm;

point2<int>				terrain::find_iter(const point3<double> &object) const
{
	return ((point2<int>(object) - point2<int>(MOD1_TERRAIN_START)) / MOD1_TERRAIN_DELTA);
}