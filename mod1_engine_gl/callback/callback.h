#pragma once

#include "mod1_engine_gl/namespace.h"

class				mod1_engine_gl::callback
{
public :

	typedef	bool	(*functor_type)(int glwf_key, void *ptr);

					callback(functor_type functor, void *ptr);
					~callback() = default;

	bool			run(int key) const;

private :

	functor_type	functor;
	void 			*ptr;
};
