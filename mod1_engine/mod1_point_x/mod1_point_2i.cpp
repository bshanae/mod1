#include "mod1_point_x.h"

				mod1_point_2i::mod1_point_2i(int x, int y)
{
	this->x = x;
	this->y = y;
}

int				&mod1_point_2i::operator[](int i)
{
	switch (i)
	{
		case 0 :
			return (x);
		case 1 :
			return (y);
		default :
			global_error->raise_warning("Point 2i : Incorrect index");
	}
	return (x);
}

const int		&mod1_point_2i::operator[](int i) const
{
	switch (i)
	{
		case 0 :
			return (x);
		case 1 :
			return (y);
		default :
			global_error->raise_warning("Point 2i : Incorrect index");
	}
	return (x);
}
