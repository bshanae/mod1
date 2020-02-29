#include "model.h"

using namespace		mod1_engine_gl;

void 				model::set_as_built()
{
	MOD1_INTERNAL(is_built) = true;
}

void				model::set_as_loaded()
{
	MOD1_INTERNAL(is_loaded) = true;
}

void 				model::set_as_dynamic()
{
	if (MOD1_INTERNAL(is_built))
		throw (exception_dynamic_a());

	MOD1_INTERNAL(is_dynamic) = true;
}