#include "callback.h"

using namespace		mod1_engine_gl;

					callback::callback(functor_type functor, void *ptr)
{
	this->functor = functor;
	this->ptr = ptr;
}

void				callback::run(const event &event) const
{
	functor(event, ptr);
}
