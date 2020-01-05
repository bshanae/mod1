#pragma once

#include <exception>

template				<typename  type>
class 					mod1_buffer
{
public :

						mod1_buffer() = default;
						~mod1_buffer()
	{
		if (size_internal)
			delete []data_internal;
	}

	struct				exception_not_allocated : public std::exception
	{
		const char		*what() const noexcept override
		{
			return ("Mod1 Buffer : Buffer isn't allocated");
		}
	};

	struct				exception_cant_allocate : public std::exception
	{
		const char		*what() const noexcept override
		{
			return ("Mod1 Buffer : Can't allocate memory");
		}
	};

	struct				exception_logic : public std::exception
	{
		const char		*what() const noexcept override
		{
			return ("Mod1 Buffer : Buffer shouldn't be allocated more than once");
		}
	};

	struct				exception_bad_size : public std::exception
	{
		const char		*what() const noexcept override
		{
			return ("Mod1 Buffer : Bad size");
		}
	};

	struct				exception_bad_index : public std::exception
	{
		const char		*what() const noexcept override
		{
			return ("Mod1 Buffer : Bad index");
		}
	};

	void 				allocate(int size)
	{
		if (data_internal)
			throw (exception_logic());
		if (size < 1)
			throw (exception_bad_size());
		data_internal = new type[size];
		if (!data_internal)
			throw (exception_cant_allocate());
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
		return (size_internal * sizeof(type));
	}

	void 				set(const type &value)
	{
		if (!size_internal)
			throw (exception_not_allocated());
		for (int i = 0; i < size_internal; i++)
			data_internal[i] = value;
	}

	void 				copy(const type *source)
	{
		if (!size_internal)
			throw (exception_not_allocated());
		memcpy(data_internal, source, size_internal);
	}

	type				&operator [] (int index)
	{
		if (!is_valid(index))
			throw (exception_bad_index());
		return (data_internal[index]);
	}

	const type			&operator [] (int index) const
	{
		if (!is_valid(index))
			throw (exception_bad_index());
		return (data_internal[index]);
	}

	type				*operator + (int index)
	{
		if (!is_valid(index))
			throw (exception_bad_index());
		return (data_internal + index);
	}

	const type			*operator + (int index) const
	{
		if (!is_valid(index))
			throw (exception_bad_index());
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