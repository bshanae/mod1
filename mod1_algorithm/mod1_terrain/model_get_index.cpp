#include "mod1_terrain.h"

int						mod1_terrain::model_get_index(const mod1_point2<int> &iter)
{
	if (iter.x < 0 || iter.x >= model_size.x)
		throw (mod1_terrain::exception_bad_coordinate());
	if (iter.y < 0 || iter.y >= model_size.y)
		throw (mod1_terrain::exception_bad_coordinate());
	return (iter.y * model_size.x + iter.x);
}