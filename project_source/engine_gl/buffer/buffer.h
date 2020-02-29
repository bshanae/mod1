#pragma once

#include "engine_gl/namespace.h"

template				<typename type>
class 					mod1_engine_gl::buffer
{
public :

						buffer() = default;
						~buffer()
	{
		if (MOD1_INTERNAL(size))
			delete []MOD1_INTERNAL(data);
	}

MOD1_GENERATE_EXCEPTION(exception_allocation_a, "Mod1 Engine GL, Buffer : Can't allocate memory")
MOD1_GENERATE_EXCEPTION(exception_allocation_b, "Mod1 Engine GL, Buffer : Buffer isn't allocated")
MOD1_GENERATE_EXCEPTION(exception_logic_a, "Mod1 Engine GL, Buffer : Buffer shouldn't be allocated more than once")
MOD1_GENERATE_EXCEPTION(exception_logic_b, "Mod1 Engine GL, Buffer : Source buffer has different size")
MOD1_GENERATE_EXCEPTION(exception_size, "Mod1 Engine GL, Buffer : Bad size")
MOD1_GENERATE_EXCEPTION(exception_index, "Mod1 Engine GL, Buffer : Bad index")

	bool				is_allocated() const
	{
		return (MOD1_INTERNAL(data) != nullptr);
	}

	void 				allocate(int size)
	{
		if (MOD1_INTERNAL(data))
			throw (exception_logic_a());
		if (size < 1)
			throw (exception_size());
		MOD1_INTERNAL(data) = new type[size];
		if (!MOD1_INTERNAL(data))
			throw (exception_allocation_a());
		this->MOD1_INTERNAL(size) = size;
	}

	int 				size_in_bytes() const
	{
		if (!MOD1_INTERNAL(size))
			throw (exception_allocation_b());
		return (MOD1_INTERNAL(size) * sizeof(type));
	}

	void 				set(const type &value)
	{
		if (!MOD1_INTERNAL(size))
			throw (exception_allocation_b());
		for (int i = 0; i < MOD1_INTERNAL(size); i++)
			MOD1_INTERNAL(data)[i] = value;
	}

	void 				copy(const type *source)
	{
		if (!MOD1_INTERNAL(size))
			throw (exception_allocation_b());
		memcpy(MOD1_INTERNAL(data), source, MOD1_INTERNAL(size) * sizeof(type));
	}

	void 				copy(const buffer<type> &source)
	{
		if (!MOD1_INTERNAL(size))
			throw (exception_allocation_b());
		if (MOD1_INTERNAL(size) != source.size())
			throw (exception_logic_b());
		memcpy(MOD1_INTERNAL(data), source.data(), MOD1_INTERNAL(size) * sizeof(type));
	}

	type				&operator [] (int index)
	{
		if (!is_valid(index))
			throw (exception_index());
		return (MOD1_INTERNAL(data)[index]);
	}

	const type			&operator [] (int index) const
	{
		if (!is_valid(index))
			throw (exception_index());
		return (MOD1_INTERNAL(data)[index]);
	}

	type				*operator + (int index)
	{
		if (!is_valid(index))
			throw (exception_index());
		return (MOD1_INTERNAL(data) + index);
	}

	const type			*operator + (int index) const
	{
		if (!is_valid(index))
			throw (exception_index());
		return (MOD1_INTERNAL(data) + index);
	}

	bool 				is_valid(const int &index) const
	{
		return (index >= 0 && index < MOD1_INTERNAL(size));
	}

private :

MOD1_GENERATE_INTERNAL_WITH_VALUE(type *, data, nullptr)
MOD1_GENERATE_INTERNAL_WITH_VALUE(int, size, 0)

public :

MOD1_GENERATE_INTERNAL_READ(size)
MOD1_GENERATE_INTERNAL_READ(data)

};