#include "callback.h"

using namespace		mod1_engine_gl;

					callback::callback(functor_ptr functor, void *ptr) :
					type(functor_type::ptr),
					functor()
{
	this->functor.ptr = functor;
	this->ptr = ptr;
}

					callback::callback(functor_ptr_event functor, void *ptr) :
					type(functor_type::ptr_event),
					functor()
{
	this->functor.ptr_event = functor;
	this->ptr = ptr;
}

void				callback::run()
{
	if (is_blocked)
		return ;
	if (type == functor_type::ptr and functor.ptr)
		functor.ptr(ptr);
}

void				callback::run(const event &event)
{
	if (is_blocked)
		return ;
	if (type == functor_type::ptr and functor.ptr)
		functor.ptr(ptr);
	else if (type == functor_type::ptr_event and functor.ptr_event)
		functor.ptr_event(ptr, event);
}

void 				callback::block(const bool &state)
{
	is_blocked = state;
}