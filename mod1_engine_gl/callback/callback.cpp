#include "callback.h"

using namespace		mod1_engine_gl;

					callback::callback(callback_functor functor, void *ptr)
{
	this->functor = functor;
	this->ptr = ptr;
}

void				callback::run(const event &event) const
{
	functor(event, ptr);
}
