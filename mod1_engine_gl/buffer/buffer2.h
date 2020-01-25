#pragma once

#include "mod1_main/mod1_generic.h"

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/buffer/buffer.h"
#include "mod1_engine_gl/point/point2.h"

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
		if (size_internal)
			throw (exception_logic_a());
		if (size_column < 1)
			throw (exception_size());
		data_internal.allocate(size_column);
		for (int i = 0; i < size_column; i++)
			data_internal[i].allocate(size_row);
		this->size_internal = size_column;
	}

	type							*data() const
	{
		return (data_internal);
	}

	int 							size() const
	{
		return (size_internal);
	}

	void 							set(const type &value)
	{
		if (!size_internal)
			throw (exception_allocation());
		for (int i = 0; i < size_internal; i++)
			data_internal[i].set(value);
	}

	void 							copy(const buffer2<type> &source)
	{
		if (!size_internal)
			throw (exception_allocation());
		if (size_internal != source.size())
			throw (exception_logic_b());
		for (int i = 0; i < size_internal; i++)
			data_internal[i].copy(source[i]);
	}

	buffer<type>					&operator [] (int index)
	{
		if (!is_valid(index))
			throw (exception_index());
		return (data_internal[index]);
	}

	const buffer<type>				&operator [] (int index) const
	{
		if (!is_valid(index))
			throw (exception_index());
		return (data_internal[index]);
	}

	type							&operator [] (const point2<int> &iter)
	{
		if (!is_valid(iter))
			throw (exception_index());
		return (data_internal[iter.x][iter.y]);
	}

	const type						&operator [] (const point2<int> &iter) const
	{
		if (!is_valid(iter))
			throw (exception_index());
		return (data_internal[iter.x][iter.y]);
	}

	buffer<type>					*operator + (int index)
	{
		if (!is_valid(index))
			throw (exception_index());
		return (data_internal + index);
	}

	const buffer<type>				*operator + (int index) const
	{
		if (!is_valid(index))
			throw (exception_index());
		return (data_internal + index);
	}

	type							*operator + (const point2<int> &iter)
	{
		if (!is_valid(iter))
			throw (exception_index());
		return (data_internal[iter.x] + iter.y);
	}

	const type						*operator + (const point2<int> &iter) const
	{
		if (!is_valid(iter))
			throw (exception_index());
		return (data_internal[iter.x] + iter.y);
	}

	bool 							is_valid(const int &index) const
	{
		if (!size_internal)
			throw (exception_allocation());
		return (index >= 0 && index < size_internal);
	}

	bool 							is_valid(const point2<int> &iter) const
	{
		if (!size_internal)
			throw (exception_allocation());
		if (iter.x < 0 || iter.x >= size_internal)
			return (false);
		if (iter.y < 0 || iter.y >= data_internal[0].size())
			return (false);
		return (true);
	}

private :

	buffer<buffer<type>>			data_internal = buffer<buffer<type>>();
	int								size_internal = 0;
};