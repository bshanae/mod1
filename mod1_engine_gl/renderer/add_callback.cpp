#include "renderer.h"

using namespace			mod1_engine_gl;

void					renderer::add_callback(callback::functor_type functor, void *ptr)
{
	callback_array.emplace_back(callback(functor, ptr));
}