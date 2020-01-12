#pragma once

#include "mod1_main/mod1_generic.h"

#include <cmath>

MOD1_GENERATE_TEMPLATE(type)
class						mod1_engine::point3
{
public :

	MOD1_GENERATE_EXCEPTION(exception_index, "Mod1 Engine, Point3 : Bad index")
	MOD1_GENERATE_EXCEPTION(exception_axis_convention, "Mod1 Engine, Point3 : Unknown axis convention")

	type					x = 0;
	type					y = 0;
	type					z = 0;

							point3() = default;
	explicit				point3(type value)
	{
		this->x = value;
		this->y = value;
		this->z = value;
	}

							point3(type x, type y, type z = 0)
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

	explicit				point3(const type *ptr, const mod1_axis_convention &convention)
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
			throw (exception_axis_convention());
	}
							~point3() = default;

	point3<type>			operator + (const point3<type> &other) const
	{
		return (point3<type>(this->x + other.x, this->y + other.y, this->z + other.z));
	}

	point3<type>			operator - (const point3<type> &other) const
	{
		return (point3<type>(this->x - other.x, this->y - other.y, this->z - other.z));
	}

	point3<type>			operator * (const point3<type> &other) const
	{
		return (point3<type>(this->x * other.x, this->y * other.y, this->z * other.z));
	}

	template 			<typename t2>
	point3<type>			operator * (const t2 &other) const
	{
		return (point3<type>(this->x * other, this->y * other, this->z * other));
	}

	point3<type>			operator / (const point3<type> &other) const
	{
		return (point3<type>(this->x / other.x, this->y / other.y, this->z / other.z));
	}

	template 			<typename t2>
	point3<type>			operator / (const t2 &other) const
	{
		return (point3<type>(this->x / other, this->y / other, this->z / other));
	}

	void					operator += (const point3<type> &other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void					operator -= (const point3<type> &other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z += other.z;
	}

	void					operator *= (const point3<type> &other)
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

	void					operator /= (const point3<type> &other)
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

	point3<type>			dot(const point3<type> &other) const
	{
		return (point3<type>(
			this->x * other->x,
			this->y * other->y,
			this->z * other->z));
	}

	static void				dot(const point3<type> &a, const point3<type> &b)
	{
		return (point3<type>(
			a->x * b->x,
			a->y * b->y,
			a->z * b->z));
	}

	point3<type>			cross(const point3<type> &other) const
	{
		return (point3<type>(
			this->y * other.z - this->z * other.y,
			this->z * other.x - this->x * other.z,
			this->x * other.y - this->y * other.x));
	}

	static point3<type>		cross(const point3<type> &a, const point3<type> &b)
	{
		return (point3<type>(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
	}

	type					&operator [] (int i)
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

	const type				&operator [] (int i) const
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
	explicit				operator point3<t2> () const
	{
		return (point3<t2>(this->x, this->y, this->z));
	}

	template 			<class p2>
	point3<type>			&operator = (const p2 &point2)
	{
		this->x = point2.x;
		this->y = point2.y;
		return (*this);
	}

	bool					operator == (const point3<type> &other)
	{
		if (this->x != other.x)
			return (false);
		if (this->y != other.y)
			return (false);
		if (this->z != other.z)
			return (false);
		return (true);
	}

	static point3<type>		min (const point3<type> &a, const point3<type> &b)
	{
		return (point3<type>(MOD1_MIN(a.x, b.x), MOD1_MIN(a.y, b.y), MOD1_MIN(a.z, b.z)));
	}

	static point3<type>		max (const point3<type> &a, const point3<type> &b)
	{
		return (point3<type>(MOD1_MAX(a.x, b.x), MOD1_MAX(a.y, b.y), MOD1_MAX(a.z, b.z)));
	}

	void 					write_to_ptr(type *ptr, const mod1_axis_convention &convention) const
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
			throw (exception_axis_convention());
	}

	type					length() const
	{
		return (sqrt(
			this->x * this->x +
			this->y * this->y +
			this->z * this->z));
	}

	void 					normalize()
	{
		type				length = this->length();

		this->x /= length;
		this->y /= length;
		this->z /= length;
	}

	static point3<type>		normalize(const point3<type> &point)
	{
		type				length = point->length();

		return (point3<type>(point->x / length, point->y / length, point->z / length));
	}

	point3<type>	 		normalized() const
	{
		type				length = this->length();

		return (point3<type>(this->x / length, this->y / length, this->z / length));
	}
};
