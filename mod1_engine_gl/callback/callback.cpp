#include "callback.h"

using namespace		mod1_engine_gl;

					callback::callback(functor_type functor, void *ptr)
{
	this->functor = functor;
	this->ptr = ptr;
}

bool				callback::run(int key) const
{
	return (functor(key, ptr));
}
