#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/event/event.h"

class				mod1_engine_gl::callback
{
public :

	typedef	void	(*functor_type)(const event &event, void *ptr);

					callback(functor_type functor, void *ptr);
					~callback() = default;

	void			run(const event &event) const;

private :

	functor_type	functor;
	void 			*ptr;
};
