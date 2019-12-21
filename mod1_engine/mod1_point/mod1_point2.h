#pragma once

#include "mod1_error.h"

template				<typename t1>
class					mod1_point2
{
public :

	t1					x = 0;
	t1					y = 0;

						mod1_point2() = default;
	explicit			mod1_point2(t1 value)
	{
		this->x = value;
		this->y = value;
	}
						mod1_point2(t1 x, t1 y)
	{
		this->x = x;
		this->y = y;
	}
						~mod1_point2() = default;

	mod1_point2<t1>		operator + (const mod1_point2<t1> &other) const
	{
		return (mod1_point2<t1>(this->x + other.x, this->y + other.y));
	}

	mod1_point2<t1>		operator - (const mod1_point2<t1> &other) const
	{
		return (mod1_point2<t1>(this->x - other.x, this->y - other.y));
	}

	mod1_point2<t1>		operator * (const mod1_point2<t1> &other) const
	{
		return (mod1_point2<t1>(this->x * other.x, this->y * other.y));
	}

	template 			<typename t2>
	mod1_point2<t1>		operator * (const t2 &other) const
	{
		return (mod1_point2<t1>(this->x * other, this->y * other));
	}

	mod1_point2<t1>		operator / (const mod1_point2<t1> &other) const
	{
		return (mod1_point2<t1>(this->x / other.x, this->y / other.y));
	}

	template 			<typename t2>
	mod1_point2<t1>		operator / (const t2 &other) const
	{
		return (mod1_point2<t1>(this->x / other, this->y / other));
	}

	void				operator += (const mod1_point2<t1> &other)
	{
		this->x += other.x;
		this->y += other.y;
	}

	void				operator -= (const mod1_point2<t1> &other)
	{
		this->x -= other.x;
		this->y -= other.y;
	}

	void				operator *= (const mod1_point2<t1> &other)
	{
		this->x *= other.x;
		this->y *= other.y;
	}

	template 			<typename t2>
	void				operator *= (const t2 &other)
	{
		this->x *= other;
		this->y *= other;
	}

	void				operator /= (const mod1_point2<t1> &other)
	{
		this->x /= other.x;
		this->y /= other.y;
	}

	template 			<typename t2>
	void				operator /= (const t2 &other)
	{
		this->x /= other;
		this->y /= other;
	}

	t1				&operator [] (int i)
	{
		switch (i)
		{
			case 0 :
				return (x);
			case 1 :
				return (y);
			default :
				global_error->raise_warning("Point2 : Incorrect index");
		}
		return (x);
	}

	const t1			&operator [] (int i) const
	{
		switch (i)
		{
			case 0 :
				return (x);
			case 1 :
				return (y);
			default :
				global_error->raise_warning("Point2 : Incorrect index");
		}
		return (x);
	}

	template 			<class p3>
	mod1_point2<t1>		&operator = (const p3 &point3)
	{
		this->x = point3.x;
		this->y = point3.y;
		return (*this);
	}

	bool				operator == (const mod1_point2<t1> &other)
	{
		if (this->x != other.x)
			return (false);
		if (this->y != other.y)
			return (false);
		return (true);
	}
};
