#pragma once

#include <exception>

template				<typename t1>
class						mod1_point3
{
public :

	struct					exception_bad_index : public std::exception
	{
		const char *		what() const noexcept override
		{
			return ("Mod1 Point3 : Bad index");
		}
	};

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
							mod1_point3(t1 x, t1 y, t1 z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
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
				throw (exception_bad_index());
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
				throw (exception_bad_index());
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
};
