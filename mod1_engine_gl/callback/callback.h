#pragma once

#include "mod1_engine_gl/namespace.h"

#include "mod1_engine_gl/event/event.h"

enum class					mod1_engine_gl::functor_type
{
	ptr,
	ptr_event
};

class						mod1_engine_gl::callback
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_run, "Mod1 Engine GL, Callback : Can't run functor")

							callback(functor_ptr functor, void *ptr);
							callback(functor_ptr_event functor, void *ptr);
							~callback() = default;

	void					run();
	void					run(const event &event);

	void 					block(const bool &state);

private :

	const functor_type		type;
	union
	{
		functor_ptr 		ptr;
		functor_ptr_event	ptr_event;
	}						functor;

	void 					*ptr;

	bool 					is_blocked = false;
};
