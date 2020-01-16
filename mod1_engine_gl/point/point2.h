#pragma once

#include "mod1_main/mod1_generic.h"

#include "mod1_engine_gl/namespace.h"

MOD1_GENERATE_TEMPLATE(type)
class					mod1_engine_gl::point2
{
public :

	MOD1_GENERATE_EXCEPTION(exception_index, "Mod1 Point2 : Bad index")

	type					x = 0;
	type					y = 0;

						point2() = default;
	explicit			point2(type value)
	{
		this->x = value;
		this->y = value;
	}
						point2(type x, type y)
	{
		this->x = x;
		this->y = y;
	}
						~point2() = default;

	point2<type>		operator + (const point2<type> &other) const
	{
		return (point2<type>(this->x + other.x, this->y + other.y));
	}

	point2<type>		operator - (const point2<type> &other) const
	{
		return (point2<type>(this->x - other.x, this->y - other.y));
	}

	point2<type>		operator * (const point2<type> &other) const
	{
		return (point2<type>(this->x * other.x, this->y * other.y));
	}

	template 			<typename t2>
	point2<type>		operator * (const t2 &other) const
	{
		return (point2<type>(this->x * other, this->y * other));
	}

	point2<type>		operator / (const point2<type> &other) const
	{
		return (point2<type>(this->x / other.x, this->y / other.y));
	}

	template 			<typename t2>
	point2<type>		operator / (const t2 &other) const
	{
		return (point2<type>(this->x / other, this->y / other));
	}

	void				operator += (const point2<type> &other)
	{
		this->x += other.x;
		this->y += other.y;
	}

	void				operator -= (const point2<type> &other)
	{
		this->x -= other.x;
		this->y -= other.y;
	}

	void				operator *= (const point2<type> &other)
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

	void				operator /= (const point2<type> &other)
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

	type					&operator [] (int i)
	{
		switch (i)
		{
			case 0 :
				return (x);
			case 1 :
				return (y);
			default :
				throw (exception_index());
		}
	}

	const type			&operator [] (int i) const
	{
		switch (i)
		{
			case 0 :
				return (x);
			case 1 :
				return (y);
			default :
				throw (exception_index());
		}
	}

	template 			<typename t2>
	explicit			operator point2<t2> () const
	{
		return (point2<t2>(this->x, this->y));
	}

	template 			<class point_like>
	point2<type>		&operator = (const point_like &point)
	{
		this->x = point.x;
		this->y = point.y;
		return (*this);
	}

	bool				operator == (const point2<type> &other)
	{
		if (this->x != other.x)
			return (false);
		if (this->y != other.y)
			return (false);
		return (true);
	}

	static point2<type>	min (const point2<type> &a, const point2<type> &b)
	{
		return (point2<type>(MOD1_MIN(a.x, b.x), MOD1_MIN(a.y, b.y)));
	}

	static point2<type>	max (const point2<type> &a, const point2<type> &b)
	{
		return (point2<type>(MOD1_MAX(a.x, b.x), MOD1_MAX(a.y, b.y)));
	}
};
