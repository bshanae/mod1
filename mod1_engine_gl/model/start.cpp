#include "model.h"

using namespace		mod1_engine_gl;

void				model::start() const
{
	if (!is_built)
		throw (exception_build());
	if (!is_loaded)
		throw (exception_load());
	vao->bind();
}