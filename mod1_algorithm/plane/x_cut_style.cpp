#include "plane.h"

using namespace		mod1_algorithm;

void				plane::switch_cut_style(const point2<int> &iter)
{
	switch (cut_style_data[iter])
	{
		case cut_style::upwards :
			cut_style_data[iter] = cut_style::downwards;
			break;
		case cut_style::downwards :
			cut_style_data[iter] = cut_style::upwards;
			break ;
		default :
			throw (exception_cut_style());
	}

	int				top_left;
	int				top_right;
	int				bottom_left;
	int				bottom_right;

	top_left = index(point2<int>(iter.x, iter.y),
					 is_dual(iter) ? index_convention::dual_second : index_convention::dual_first);
	top_right = index(point2<int>(iter.x + 1, iter.y), index_convention::dual_first);
	bottom_left = index(point2<int>(iter.x, iter.y + 1));
	bottom_right = index(point2<int>(iter.x + 1, iter.y + 1));

	int				*ptr;

	ptr = is_dual(iter) ?
		(int *) pointer(iter, model_slot::index, index_convention::dual_second) :
		(int *) pointer(iter, model_slot::index, index_convention::single);

	if (get_cut_style(iter) == cut_style::upwards)
	{
		ptr[0] = top_left;
		ptr[1] = bottom_left;
		ptr[2] = top_right;

		ptr[3] = top_right;
		ptr[4] = bottom_left;
		ptr[5] = bottom_right;
	}
	else
	{
		ptr[0] = top_left;
		ptr[1] = bottom_left;
		ptr[2] = bottom_right;

		ptr[3] = top_right;
		ptr[4] = top_left;
		ptr[5] = bottom_right;
	}
}

plane::cut_style 	plane::get_cut_style(const point2<int> &iter)
{
	return (cut_style_data[iter]);
}