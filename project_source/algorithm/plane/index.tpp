#pragma once

using namespace		mod1_algorithm;

template			<typename color_type>
int 				plane<color_type>::index(
					const point2<int> &iter,
					const index_convention &convention) const
{
	switch (convention)
	{
		case index_convention::single :
		{
			if (iter.x < 0 || iter.x >= MOD1_PLANE_REAL_SIZE_X(MOD1_INTERNAL(size).x))
				throw (exception_coordinate());
			if (iter.y < 0 || iter.y >= MOD1_INTERNAL(size).y)
				throw (exception_coordinate());
			return (iter.y * MOD1_PLANE_REAL_SIZE_X(MOD1_INTERNAL(size).x) + iter.x);
		}
		case index_convention::dual_first :
		{
			if (iter.x < 0 || iter.x >= MOD1_INTERNAL(size).x)
				throw (exception_coordinate());
			if (iter.y < 0 || iter.y >= MOD1_INTERNAL(size).y)
				throw (exception_coordinate());
			return (iter.y * MOD1_PLANE_REAL_SIZE_X(MOD1_INTERNAL(size).x)
					+ MOD1_PLANE_REAL_INDEX_X(iter.x));
		}
		case index_convention::dual_second :
		{
			if (iter.x < 0 || iter.x >= MOD1_INTERNAL(size).x)
				throw (exception_coordinate());
			if (iter.y < 0 || iter.y >= MOD1_INTERNAL(size).y)
				throw (exception_coordinate());
			return (iter.y * MOD1_PLANE_REAL_SIZE_X(MOD1_INTERNAL(size).x)
					+ MOD1_PLANE_REAL_INDEX_X(iter.x) + 1);
		}
		default :
			throw (exception_index_convention());
	}
}