#pragma once

class				mod1_point_2i
{
public :

	int				x = 0;
	int				y = 0;

					mod1_point_2i() = default;
					mod1_point_2i(int x, int y);
					~mod1_point_2i() = default;
};

class				mod1_point_2f
{
public :

	float			x = 0.f;
	float			y = 0.f;

					mod1_point_2f() = default;
					mod1_point_2f(float x, float y);
					~mod1_point_2f() = default;
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

	mod1_point_2f	point_2f();
};


