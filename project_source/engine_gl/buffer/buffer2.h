#pragma once

#include "engine_gl/namespace.h"

#include "engine_gl/buffer/buffer.h"
#include "engine_gl/point/point2.h"

template							<typename type>
class 								mod1_engine_gl::buffer2
{
public :

									buffer2() = default;
									~buffer2() = default;

	MOD1_GENERATE_EXCEPTION(exception_allocation, "Mod1 Engine GL, Buffer2 : Buffer isn't allocated")
	MOD1_GENERATE_EXCEPTION(exception_logic_a, "Mod1 Engine GL, Buffer2 : Buffer shouldn't be allocated more than once")
	MOD1_GENERATE_EXCEPTION(exception_logic_b, "Mod1 Engine GL, Buffer2 : Source buffer has different size")
	MOD1_GENERATE_EXCEPTION(exception_size, "Mod1 Engine GL, Buffer2 : Bad size")
	MOD1_GENERATE_EXCEPTION(exception_index, "Mod1 Engine GL, Buffer2 : Bad index")

	void 							allocate(int size_column, int size_row)
	{
		if (MOD1_INTERNAL(size))
			throw (exception_logic_a());
		if (size_column < 1)
			throw (exception_size());
		MOD1_INTERNAL(data).allocate(size_column);
		for (int i = 0; i < size_column; i++)
			MOD1_INTERNAL(data)[i].allocate(size_row);
		this->MOD1_INTERNAL(size) = size_column;
	}

	void 							set(const type &value)
	{
		if (!MOD1_INTERNAL(size))
			throw (exception_allocation());
		for (int i = 0; i < MOD1_INTERNAL(size); i++)
			MOD1_INTERNAL(data)[i].set(value);
	}

	void 							copy(const buffer2<type> &source)
	{
		if (!MOD1_INTERNAL(size))
			throw (exception_allocation());
		if (MOD1_INTERNAL(size) != source.size())
			throw (exception_logic_b());
		for (int i = 0; i < MOD1_INTERNAL(size); i++)
			MOD1_INTERNAL(data)[i].copy(source[i]);
	}

	buffer<type>					&operator [] (int index)
	{
		if (!is_valid(index))
			throw (exception_index());
		return (MOD1_INTERNAL(data)[index]);
	}

	const buffer<type>				&operator [] (int index) const
	{
		if (!is_valid(index))
			throw (exception_index());
		return (MOD1_INTERNAL(data)[index]);
	}

	type							&operator [] (const point2<int> &iter)
	{
		if (!is_valid(iter))
			throw (exception_index());
		return (MOD1_INTERNAL(data)[iter.x][iter.y]);
	}

	const type						&operator [] (const point2<int> &iter) const
	{
		if (!is_valid(iter))
			throw (exception_index());
		return (MOD1_INTERNAL(data)[iter.x][iter.y]);
	}

	buffer<type>					*operator + (int index)
	{
		if (!is_valid(index))
			throw (exception_index());
		return (MOD1_INTERNAL(data) + index);
	}

	const buffer<type>				*operator + (int index) const
	{
		if (!is_valid(index))
			throw (exception_index());
		return (MOD1_INTERNAL(data) + index);
	}

	type							*operator + (const point2<int> &iter)
	{
		if (!is_valid(iter))
			throw (exception_index());
		return (MOD1_INTERNAL(data)[iter.x] + iter.y);
	}

	const type						*operator + (const point2<int> &iter) const
	{
		if (!is_valid(iter))
			throw (exception_index());
		return (MOD1_INTERNAL(data)[iter.x] + iter.y);
	}

	bool 							is_valid(const int &index) const
	{
		if (!MOD1_INTERNAL(size))
			throw (exception_allocation());
		return (index >= 0 && index < MOD1_INTERNAL(size));
	}

	bool 							is_valid(const point2<int> &iter) const
	{
		if (!MOD1_INTERNAL(size))
			throw (exception_allocation());
		if (iter.x < 0 || iter.x >= MOD1_INTERNAL(size))
			return (false);
		if (iter.y < 0 || iter.y >= MOD1_INTERNAL(data)[0].size())
			return (false);
		return (true);
	}

private :

MOD1_GENERATE_INTERNAL(buffer<buffer<type>>, data)
MOD1_GENERATE_INTERNAL_WITH_VALUE(int, size, 0)

public :

MOD1_GENERATE_INTERNAL_READ(size)
MOD1_GENERATE_INTERNAL_READ(data)
};