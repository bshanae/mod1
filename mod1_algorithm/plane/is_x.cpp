#include "plane.h"

using namespace		mod1_algorithm;

bool 				plane::is_dual(const point2<int> &iter) const
{
	return (iter.x > 0 && iter.x < MOD1_INTERNAL(size).x - 1 && iter.y < MOD1_INTERNAL(size).y - 1);
}