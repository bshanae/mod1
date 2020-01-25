#pragma once

#include "mod1_main/mod1_generic.h"

#include "mod1_engine_gl/namespace.h"

#include <string>

template				<typename type>
class 					mod1_engine_gl::buffer
{
public :

						buffer() = default;
						~buffer()
	{
		if (size_internal)
			delete []data_internal;
	}

	MOD1_GENERATE_EXCEPTION(exception_allocation_a, "Mod1 Engine GL, Buffer : Can't allocate memory")
	MOD1_GENERATE_EXCEPTION(exception_allocation_b, "Mod1 Engine GL, Buffer : Buffer isn't allocated")
	MOD1_GENERATE_EXCEPTION(exception_logic_a, "Mod1 Engine GL, Buffer : Buffer shouldn't be allocated more than once")
	MOD1_GENERATE_EXCEPTION(exception_logic_b, "Mod1 Engine GL, Buffer : Source buffer has different size")
	MOD1_GENERATE_EXCEPTION(exception_size, "Mod1 Engine GL, Buffer : Bad size")
	MOD1_GENERATE_EXCEPTION(exception_index, "Mod1 Engine GL, Buffer : Bad index")

	void 				allocate(int size)
	{
		if (data_internal)
			throw (exception_logic_a());
		if (size < 1)
			throw (exception_size());
		data_internal = new type[size];
		if (!data_internal)
			throw (exception_allocation_a());
		this->size_internal = size;
	}

	type				*data() const
	{
		return (data_internal);
	}

	int 				size() const
	{
		return (size_internal);
	}

	int 				size_in_bytes() const
	{
		if (!size_internal)
			throw (exception_allocation_b());
		return (size_internal * sizeof(type));
	}

	void 				set(const type &value)
	{
		if (!size_internal)
			throw (exception_allocation_b());
		for (int i = 0; i < size_internal; i++)
			data_internal[i] = value;
	}

	void 				copy(const type *source)
	{
		if (!size_internal)
			throw (exception_allocation_b());
		memcpy(data_internal, source, size_internal * sizeof(type));
	}

	void 				copy(const buffer<type> &source)
	{
		if (!size_internal)
			throw (exception_allocation_b());
		if (size_internal != source.size())
			throw (exception_logic_b());
		memcpy(data_internal, source.data(), size_internal * sizeof(type));
	}

	type				&operator [] (int index)
	{
		if (!is_valid(index))
			throw (exception_index());
		return (data_internal[index]);
	}

	const type			&operator [] (int index) const
	{
		if (!is_valid(index))
			throw (exception_index());
		return (data_internal[index]);
	}

	type				*operator + (int index)
	{
		if (!is_valid(index))
			throw (exception_index());
		return (data_internal + index);
	}

	const type			*operator + (int index) const
	{
		if (!is_valid(index))
			throw (exception_index());
		return (data_internal + index);
	}

	bool 				is_valid(const int &index) const
	{
		return (index >= 0 && index < size_internal);
	}

private :

	type				*data_internal = nullptr;
	int 				size_internal = 0;
};