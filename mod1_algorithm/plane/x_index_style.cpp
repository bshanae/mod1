#include "plane.h"

using namespace		mod1_algorithm;

void				plane::switch_index_style(const point2<int> &iter)
{
	int				top_left;
	int				top_right;
	int				bottom_left;
	int				bottom_right;

	top_left = get_index(point2<int>(iter.x, iter.y),
		is_dual(iter) ? index_convention::dual_second : index_convention::dual_first);
	top_right = get_index(point2<int>(iter.x + 1, iter.y), index_convention::dual_first);
	bottom_left = get_index(point2<int>(iter.x, iter.y + 1));
	bottom_right = get_index(point2<int>(iter.x + 1, iter.y + 1));

	int				*ptr;

	ptr = (int *)get_ptr(iter, model_slot::index);

	ptr[0] = top_left;
	ptr[1] = bottom_left;
	ptr[2] = bottom_right;

	ptr[3] = top_right;
	ptr[4] = top_left;
	ptr[5] = bottom_right;
}

void 					plane::get_index_style(const point2<int> &iter)
{

}