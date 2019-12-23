#pragma once

#include "mod1_error.h"

template			<typename  type>
class 				mod1_buffer
{
public :

					mod1_buffer() = default;
					~mod1_buffer()
	{
		if (size_internal)
			delete []data_internal;
	}

	void 			allocate(int size)
	{
		if (data_internal)
			global_error->raise_error("Buffer : Shouldn't allocate buffer more than once");
		data_internal = new type[size];
		if (!data_internal)
			global_error->raise_error("Buffer : Can't allocate buffer");
		this->size_internal = size;
	}

	type			*data() const
	{
		return (data_internal);
	}

	int 			size() const
	{
		return (size_internal);
	}

private :

	type			*data_internal = nullptr;
	int 			size_internal = 0;
};