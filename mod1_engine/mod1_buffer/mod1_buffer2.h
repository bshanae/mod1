#pragma once

#include "mod1_buffer.h"
#include "mod1_point2.h"

template							<typename  type>
class 								mod1_buffer2
{
public :

									mod1_buffer2() = default;
									~mod1_buffer2() = default;

	struct							exception_not_allocated : public std::exception
	{
		const char					*what() const noexcept override
		{
			return ("Mod1 Buffer2 : Buffer isn't allocated");
		}
	};

	struct							exception_logic : public std::exception
	{
		const char					*what() const noexcept override
		{
			return ("Mod1 Buffer2 : Buffer shouldn't be allocated more than once");
		}
	};

	struct							exception_bad_size : public std::exception
	{
		const char 					*what() const noexcept override
		{
			return ("Mod1 Buffer2 : Bad size");
		}
	};
	struct							exception_bad_index : public std::exception
	{
		const char 					*what() const noexcept override
		{
			return ("Mod1 Buffer2 : Bad index");
		}
	};

	void 							allocate(int size_column, int size_row)
	{
		if (size_internal)
			throw (exception_logic());
		if (size_column < 1)
			throw (exception_bad_size());
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
			throw (exception_not_allocated());
		for (int i = 0; i < size_internal; i++)
			data_internal[i].set(value);
	}

	mod1_buffer<type>				&operator [] (int index)
	{
		if (index < 0 || index >= size_internal)
			throw (exception_bad_index());
		return (data_internal[index]);
	}

	const mod1_buffer<type>			&operator [] (int index) const
	{
		if (index < 0 || index >= size_internal)
			throw (exception_bad_index());
		return (data_internal[index]);
	}

	type							&operator [] (const mod1_point2<int> &iter)
	{
		return (data_internal[iter.x][iter.y]);
	}

	const type						&operator [] (const mod1_point2<int> &iter) const
	{
		return (data_internal[iter.x][iter.y]);
	}

private :

	mod1_buffer<mod1_buffer<type>>	data_internal;
	int								size_internal = 0;
};