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

	struct							exception_logic_a : public std::exception
	{
		const char					*what() const noexcept override
		{
			return ("Mod1 Buffer2 : Buffer shouldn't be allocated more than once");
		}
	};

	struct							exception_logic_b : public std::exception
	{
		const char					*what() const noexcept override
		{
			return ("Mod1 Buffer2 : Source buffer has different size");
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
			throw (exception_logic_a());
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

	void 							copy(const mod1_buffer2<type> &source)
	{
		if (!size_internal)
			throw (exception_not_allocated());
		if (size_internal != source.size())
			throw (exception_logic_b());
		for (int i = 0; i < size_internal; i++)
			data_internal[i].copy(source[i]);
	}

	mod1_buffer<type>				&operator [] (int index)
	{
		if (!is_valid(index))
			throw (exception_bad_index());
		return (data_internal[index]);
	}

	const mod1_buffer<type>			&operator [] (int index) const
	{
		if (!is_valid(index))
			throw (exception_bad_index());
		return (data_internal[index]);
	}

	type							&operator [] (const mod1_point2<int> &iter)
	{
		if (!is_valid(iter))
			throw (exception_bad_index());
		return (data_internal[iter.x][iter.y]);
	}

	const type						&operator [] (const mod1_point2<int> &iter) const
	{
		if (!is_valid(iter))
			throw (exception_bad_index());
		return (data_internal[iter.x][iter.y]);
	}

	mod1_buffer<type>				*operator + (int index)
	{
		if (!is_valid(index))
			throw (exception_bad_index());
		return (data_internal + index);
	}

	const mod1_buffer<type>			*operator + (int index) const
	{
		if (!is_valid(index))
			throw (exception_bad_index());
		return (data_internal + index);
	}

	type							*operator + (const mod1_point2<int> &iter)
	{
		if (!is_valid(iter))
			throw (exception_bad_index());
		return (data_internal[iter.x] + iter.y);
	}

	const type						*operator + (const mod1_point2<int> &iter) const
	{
		if (!is_valid(iter))
			throw (exception_bad_index());
		return (data_internal[iter.x] + iter.y);
	}

	bool 							is_valid(const int &index) const
	{
		if (!size_internal)
			throw (exception_not_allocated());
		return (index >= 0 && index < size_internal);
	}

	bool 							is_valid(const mod1_point2<int> &iter) const
	{
		if (!size_internal)
			throw (exception_not_allocated());
		if (iter.x < 0 || iter.x >= size_internal)
			return (false);
		if (iter.y < 0 || iter.y >= data_internal[0].size())
			return (false);
		return (true);
	}

private :

	mod1_buffer<mod1_buffer<type>>	data_internal;
	int								size_internal = 0;
};