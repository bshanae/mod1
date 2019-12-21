#pragma once

#include "mod1_error.h"

template			<typename  type>
class 				mod1_buffer
{
public :

					mod1_buffer() = default;
					~mod1_buffer()
	{
		if (internal_size)
			delete []internal_data;
	}

	void 			allocate(int size)
	{
		internal_data = new type[size];
		if (!internal_data)
			global_error->raise_error("Buffer : Can't allocate memory");
		this->internal_size = size;
	}

	type			*data() const
	{
		return (internal_data);
	}

	int 			size() const
	{
		return (internal_size);
	}

private :

	type			*internal_data = nullptr;
	int 			internal_size = 0;
};