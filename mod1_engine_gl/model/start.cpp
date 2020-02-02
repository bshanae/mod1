#include "model.h"

using namespace		mod1_engine_gl;

void				model::start() const
{
	if (not MOD1_INTERNAL(is_built))
		throw (exception_build());
	if (not MOD1_INTERNAL(is_loaded))
		throw (exception_load());
	vao->bind();
}