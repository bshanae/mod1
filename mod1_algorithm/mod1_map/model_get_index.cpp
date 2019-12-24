#include "mod1_map.h"

int						mod1_map::model_get_index(const mod1_point2<int> &iter)
{
	if (iter.x < 0 || iter.x >= model_size.x)
		throw (mod1_map::exception_bad_coordinate());
	if (iter.y < 0 || iter.y >= model_size.y)
		throw (mod1_map::exception_bad_coordinate());
	return (iter.y * model_size.x + iter.x);
}