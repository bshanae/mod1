#include "callback.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(callback, exception_run)

					callback::callback(functor_ptr functor, void *ptr) :
					type(functor_type::ptr)
{
	this->functor.ptr = functor;
	this->ptr = ptr;
}

					callback::callback(functor_ptr_event functor, void *ptr) :
					type(functor_type::ptr_event)
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
	else if (type == functor_type::ptr and not functor.ptr)
		;
	else
		throw (exception_run());
}

void				callback::run(const event &event)
{
	if (is_blocked)
		return ;
	if (type == functor_type::ptr_event and functor.ptr_event)
		functor.ptr_event(ptr, event);
	else if (type == functor_type::ptr_event and not functor.ptr_event)
		;
	else
		throw (exception_run());
}

void 				callback::block(const bool &state)
{
	is_blocked = state;
}