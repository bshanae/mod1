#include "mod1_plane.h"

int 				mod1_plane::get_index(const mod1_point2<int> &iter) const
{
	if (iter.x < 0 || iter.x >= size.x)
		throw (mod1_plane::exception_bad_coordinate());
	if (iter.y < 0 || iter.y >= size.y)
		throw (mod1_plane::exception_bad_coordinate());
	return (iter.y * size.x + iter.x);
}
