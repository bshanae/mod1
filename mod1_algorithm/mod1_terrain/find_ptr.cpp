#include "mod1_terrain.h"

mod1_point2<int>		mod1_terrain::find_ptr(const mod1_point3<int> &object) const
{
	mod1_point2<int>	iter;
	mod1_point3<int>	point;

	for (iter.y = 0; iter.y < size().y; iter.y++)
		for (iter.x = 0; iter.x < size().x; iter.x++)
		{
			point = (mod1_point3<int>)read_point(iter);
			if (point.x == object.x && point.y == object.y)
				return (iter);
		}
	throw (exception_search());
}