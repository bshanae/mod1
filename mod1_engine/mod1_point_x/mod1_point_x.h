#pragma once

#include "mod1_error.h"

class				mod1_point_2i
{
public :

	int				x = 0;
	int				y = 0;

					mod1_point_2i() = default;
					mod1_point_2i(int x, int y);
					~mod1_point_2i() = default;

	int				&operator[](int i);
	const int		&operator[](int i) const;
};

class				mod1_point_3f
{
public :
	float			x = 0.f;
	float			y = 0.f;
	float			z = 0.f;

					mod1_point_3f() = default;
					mod1_point_3f(float x, float y, float z);
					~mod1_point_3f() = default;

	float			&operator[](int i);
	const float		&operator[](int i) const;
};


