#include "mod1_point_x.h"

				mod1_point_2i::mod1_point_2i(int x, int y)
{
	this->x = x;
	this->y = y;
}

				mod1_point_2f::mod1_point_2f(float x, float y)
{
	this->x = x;
	this->y = y;
}

				mod1_point_3f::mod1_point_3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

mod1_point_2f	mod1_point_3f::point_2f()
{
	return (mod1_point_2f(x, y));
}