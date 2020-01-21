#include "terrain.h"

using namespace			mod1_algorithm;

point2<int>				terrain::find_point(const point3<int> &object) const
{
	point2<int>			iter;
	point3<int>			point;

	for (iter.y = 0; iter.y < size().y; iter.y++)
		for (iter.x = 0; iter.x < size().x; iter.x++)
		{
			point = (point3<int>)read_point(iter);
			if (point.x == object.x && point.y == object.y)
				return (iter);
		}
	throw (exception_search());
}