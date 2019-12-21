#pragma once

#include "mod1_error.h"

template			<typename temp>
class				mod1_point2
{
public :

	temp			x = 0;
	temp			y = 0;

					mod1_point2() = default;
					mod1_point2(temp x, temp y);
					~mod1_point2() = default;

	temp			&operator[](int i);
	const temp		&operator[](int i) const;
};

template			<typename temp>
class				mod1_point3
{
public :
	temp			x = 0;
	temp			y = 0;
	temp			z = 0;

					mod1_point3() = default;
					mod1_point3(temp x, temp y, temp z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
					~mod1_point3() = default;


	temp			&operator[](int i)
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
				global_error->raise_warning("Point3 : Incorrect index");
		}
		return (x);
	}

	const temp		&operator[](int i) const
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
				global_error->raise_warning("Point3 : Incorrect index");
		}
		return (x);
	}
};
