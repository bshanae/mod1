#include "mod1_callback.h"

					mod1_callback::mod1_callback(functor_type functor, void *ptr)
{
	this->functor = functor;
	this->ptr = ptr;
}

bool				mod1_callback::run(int key) const
{
	return (functor(key, ptr));
}
