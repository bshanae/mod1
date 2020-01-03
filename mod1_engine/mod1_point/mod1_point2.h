#pragma once

#include "mod1_min_max.h"

template				<typename t1>
class					mod1_point2
{
public :

	struct				exception_bad_index : public std::exception
	{
		const char *	what() const noexcept override
		{
			return ("Mod1 Point2 : Bad index");
		}
	};

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

	t1					&operator [] (int i)
	{
		switch (i)
		{
			case 0 :
				return (x);
			case 1 :
				return (y);
			default :
				throw (exception_bad_index());
		}
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
				throw (exception_bad_index());
		}
	}

	template 			<typename t2>
	explicit			operator mod1_point2<t2> () const
	{
		return (mod1_point2<t2>(this->x, this->y));
	}

	template 			<class point_like>
	mod1_point2<t1>		&operator = (const point_like &point)
	{
		this->x = point.x;
		this->y = point.y;
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

	static mod1_point2<t1>	min (const mod1_point2<t1> &a, const mod1_point2<t1> &b)
	{
		return (mod1_point2<t1>(MOD1_MIN(a.x, b.x), MOD1_MIN(a.y, b.y)));
	}

	static mod1_point2<t1>	max (const mod1_point2<t1> &a, const mod1_point2<t1> &b)
	{
		return (mod1_point2<t1>(MOD1_MAX(a.x, b.x), MOD1_MAX(a.y, b.y)));
	}
};
