#pragma once

#include "mod1_exception.h"

template				<typename t1>
class						mod1_point3
{
public :

	MOD1_EXCEPTION_GENERATE(exception_index, "Mod1 Point3 : Bad index")
	MOD1_EXCEPTION_GENERATE(exception_axis_convetion, "Mod1 Point3 : Unknown axis convention")

	t1						x = 0;
	t1						y = 0;
	t1						z = 0;

							mod1_point3() = default;
	explicit				mod1_point3(t1 value)
	{
		this->x = value;
		this->y = value;
		this->z = value;
	}

							mod1_point3(t1 x, t1 y, t1 z = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	typedef enum
	{
		convention_xyz,
		convention_xzy
	}						mod1_axis_convention;

	explicit				mod1_point3(t1 *ptr, const mod1_axis_convention &convention)
	{
		if (convention == convention_xyz)
		{
			this->x = ptr[0];
			this->y = ptr[1];
			this->z = ptr[2];
		}
		else if (convention == convention_xzy)
		{
			this->x = ptr[0];
			this->y = ptr[2];
			this->z = ptr[1];
		}
		else
			throw (exception_axis_convetion());
	}
							~mod1_point3() = default;

	mod1_point3<t1>			operator + (const mod1_point3<t1> &other) const
	{
		return (mod1_point3<t1>(this->x + other.x, this->y + other.y, this->z + other.z));
	}

	mod1_point3<t1>			operator - (const mod1_point3<t1> &other) const
	{
		return (mod1_point3<t1>(this->x - other.x, this->y - other.y, this->z - other.z));
	}

	mod1_point3<t1>			operator * (const mod1_point3<t1> &other) const
	{
		return (mod1_point3<t1>(this->x * other.x, this->y * other.y, this->z * other.z));
	}

	template 			<typename t2>
	mod1_point3<t1>			operator * (const t2 &other) const
	{
		return (mod1_point3<t1>(this->x * other, this->y * other, this->z * other));
	}

	mod1_point3<t1>			operator / (const mod1_point3<t1> &other) const
	{
		return (mod1_point3<t1>(this->x / other.x, this->y / other.y, this->z / other.z));
	}

	template 			<typename t2>
	mod1_point3<t1>			operator / (const t2 &other) const
	{
		return (mod1_point3<t1>(this->x / other, this->y / other, this->z / other));
	}

	void					operator += (const mod1_point3<t1> &other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void					operator -= (const mod1_point3<t1> &other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z += other.z;
	}

	void					operator *= (const mod1_point3<t1> &other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
	}

	template 			<typename t2>
	void					operator *= (const t2 &other)
	{
		this->x *= other;
		this->y *= other;
		this->z *= other;
	}

	void					operator /= (const mod1_point3<t1> &other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
	}

	template 			<typename t2>
	void					operator /= (const t2 &other)
	{
		this->x /= other;
		this->y /= other;
		this->z /= other;
	}

	mod1_point3<t1>			dot(const mod1_point3<t1> &other) const
	{
		return (mod1_point3<t1>(
			this->x * other->x,
			this->y * other->y,
			this->z * other->z));
	}

	static void				dot(const mod1_point3<t1> &a, const mod1_point3<t1> &b)
	{
		return (mod1_point3<t1>(
			a->x * b->x,
			a->y * b->y,
			a->z * b->z));
	}

	mod1_point3<t1>			cross(const mod1_point3<t1> &other) const
	{
		return (mod1_point3<t1>(
			this->y * other.z - this->z * other.y,
			this->z * other.x - this->x * other.z,
			this->x * other.y - this->y * other.x));
	}

	static mod1_point3<t1>	cross(const mod1_point3<t1> &a, const mod1_point3<t1> &b)
	{
		return (mod1_point3<t1>(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
	}

	t1						&operator [] (int i)
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
				throw (exception_index());
		}
	}

	const t1				&operator [] (int i) const
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
				throw (exception_index());
		}
	}


	template 				<typename t2>
	explicit				operator mod1_point3<t2> () const
	{
		return (mod1_point3<t2>(this->x, this->y, this->z));
	}

	template 			<class p2>
	mod1_point3<t1>			&operator = (const p2 &point2)
	{
		this->x = point2.x;
		this->y = point2.y;
		return (*this);
	}

	bool					operator == (const mod1_point3<t1> &other)
	{
		if (this->x != other.x)
			return (false);
		if (this->y != other.y)
			return (false);
		if (this->z != other.z)
			return (false);
		return (true);
	}

	static mod1_point3<t1>	min (const mod1_point3<t1> &a, const mod1_point3<t1> &b)
	{
		return (mod1_point3<t1>(MOD1_MIN(a.x, b.x), MOD1_MIN(a.y, b.y), MOD1_MIN(a.z, b.z)));
	}

	static mod1_point3<t1>	max (const mod1_point3<t1> &a, const mod1_point3<t1> &b)
	{
		return (mod1_point3<t1>(MOD1_MAX(a.x, b.x), MOD1_MAX(a.y, b.y), MOD1_MAX(a.z, b.z)));
	}

	void 					write_to_ptr(t1 *ptr, const mod1_axis_convention &convention)
	{
		ptr[0] = this->x;
		if (convention == convention_xyz)
		{
			ptr[1] = this->y;
			ptr[2] = this->z;
		}
		else if (convention == convention_xzy)
		{
			ptr[1] = this->z;
			ptr[2] = this->y;
		}
		else
			throw (exception_axis_convetion());
	}

	t1						length() const
	{
		return (sqrt(
			this->x * this->x +
			this->y * this->y +
			this->z * this->z));
	}

	void 					normalize()
	{
		t1					length = this->length();

		this->x /= length;
		this->y /= length;
		this->z /= length;
	}

	static mod1_point3<t1>	normalize(const mod1_point3<t1> &point)
	{
		t1					length = point->length();

		return (mod1_point3<t1>(point->x / length, point->y / length, point->z / length));
	}

	mod1_point3<t1>	 		normalized() const
	{
		t1					length = this->length();

		return (mod1_point3<t1>(this->x / length, this->y / length, this->z / length));
	}
};
