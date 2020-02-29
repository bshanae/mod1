#pragma once

#include "engine_gl/namespace.h"

#include "engine_gl/point/point2.h"
#include "engine_gl/point/point3.h"

template 					<typename type>
class						mod1_engine_gl::point4
{
public :

MOD1_GENERATE_EXCEPTION(exception_index, "Mod1 Engine GL, Point4 : Bad index")

	type					x = 0;
	type					y = 0;
	type					z = 0;
	type					w = 0;

							point4() = default;

	explicit				point4(const type &value)
	{
		this->x = value;
		this->y = value;
		this->z = value;
		this->w = value;
	}

	explicit				point4(type *ptr)
	{
		this->x = ptr[0];
		this->y = ptr[1];
		this->z = ptr[2];
		this->w = ptr[3];
	}

							point4(const type &x, const type &y, const type &z, const type &w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}


	explicit				point4(const point2<type> &other, const type &z = 0, const type &w = 0)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = z;
		this->w = w;
	}

	explicit				point4(const point3<type> &other, const type &w = 0)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->w = w;
	}

							~point4() = default;

	point4<type>			operator + (const point4<type> &other) const
	{
		return (point4<type>(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other->w));
	}

	point4<type>			operator - (const point4<type> &other) const
	{
		return (point4<type>(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w));
	}

	point4<type>			operator * (const point4<type> &other) const
	{
		return (point4<type>(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w));
	}

	template	 			<typename another_type>
	point4<type>			operator * (const another_type &other) const
	{
		return (point4<type>(this->x * other, this->y * other, this->z * other, this->w * other));
	}

	point4<type>			operator / (const point4<type> &other) const
	{
		return (point4<type>(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w));
	}

	template 				<typename another_type>
	point4<type>			operator / (const another_type &other) const
	{
		return (point4<type>(this->x / other, this->y / other, this->z / other, this->w * other));
	}

	void					operator += (const point4<type> &other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;
	}

	void					operator -= (const point4<type> &other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
	}

	void					operator *= (const point4<type> &other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		this->w += other.w;
	}

	template 				<typename another_type>
	void					operator *= (const another_type &other)
	{
		this->x *= other;
		this->y *= other;
		this->z *= other;
		this->w *= other;
	}

	void					operator /= (const point4<type> &other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		this->w /= other.w;
	}

	template 				<typename another_type>
	void					operator /= (const another_type &other)
	{
		this->x /= other;
		this->y /= other;
		this->z /= other;
		this->w /= other;
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
			case 3 :
				return (w);
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
			case 3 :
				return (w);
			default :
				throw (exception_index());
		}
	}


	template 				<typename another_type>
	explicit				operator point4<another_type> () const
	{
		return (point4<another_type>(this->x, this->y, this->z, this->w));
	}

	bool					operator == (const point4<type> &other)
	{
		if (this->x != other.x)
			return (false);
		if (this->y != other.y)
			return (false);
		if (this->z != other.z)
			return (false);
		if (this->w != other.w)
			return (false);
		return (true);
	}

	void 					write_to_ptr(type *ptr) const
	{
		ptr[0] = this->x;
		ptr[1] = this->y;
		ptr[2] = this->z;
		ptr[3] = this->w;
	}

	friend std::ostream&	operator << (std::ostream& stream, const point4 &point)
	{
		stream << "(";
		stream << point.x;
		stream << ", ";
		stream << point.y;
		stream << ", ";
		stream << point.z;
		stream << ", ";
		stream << point.w;
		stream << ")";
		return (stream);
	}
};
