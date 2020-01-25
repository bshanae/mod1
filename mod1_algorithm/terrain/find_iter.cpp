#include "terrain.h"

using namespace			mod1_algorithm;

point2<int>				terrain::find_iter(const point3<double> &object) const
{
	return (point2<int>(
		(int)object.x / MOD1_TERRAIN_DELTA,
		(int)object.y / MOD1_TERRAIN_DELTA));
}