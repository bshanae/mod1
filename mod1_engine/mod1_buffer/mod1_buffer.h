#pragma once

#include "mod1_error.h"

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

	struct				exception_bad_index : public std::exception
	{
		const char *	what() const throw() override
		{
			return ("Mod1 Buffer : Bad index");
		}
	};

	void 				allocate(int size)
	{
		if (data_internal)
			global_error->raise_error("Buffer : Shouldn't allocate buffer more than once");
		data_internal = new type[size];
		if (!data_internal)
			global_error->raise_error("Buffer : Can't allocate buffer");
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

	type				&operator [] (int index)
	{
		if (index < 0 || index >= size_internal)
			throw (exception_bad_index());
		return (data_internal[index]);
	}

	const type			&operator [] (int index) const
	{
		if (index < 0 || index >= size_internal)
			throw (exception_bad_index());
		return (data_internal[index]);
	}

private :

	type				*data_internal = nullptr;
	int 				size_internal = 0;
};