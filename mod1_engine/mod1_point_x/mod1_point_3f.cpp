#include "mod1_point_x.h"

				mod1_point_3f::mod1_point_3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float			&mod1_point_3f::operator[](int i)
{
	switch (i)
	{
		case 0 :
			return (x);
		case 1 :
			return (y);
		case 2 :
			return (z);
		default :
			global_error->raise_warning("Point 3f : Incorrect index");
	}
	return (x);
}

const float		&mod1_point_3f::operator[](int i) const
{
	switch (i)
	{
		case 0 :
			return (x);
		case 1 :
			return (y);
		case 2 :
			return (z);
		default :
			global_error->raise_warning("Point 3f : Incorrect index");
	}
	return (x);
}