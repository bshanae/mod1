#pragma once

#include "mod1_error.h"

template			<typename temp>
class				mod1_point2
{
public :

	temp			x = 0;
	temp			y = 0;

					mod1_point2() = default;
					mod1_point2(temp x, temp y)
	{
		this->x = x;
		this->y = y;
	}
					~mod1_point2() = default;

	temp			&operator[](int i)
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

	const temp		&operator[](int i) const
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
};
