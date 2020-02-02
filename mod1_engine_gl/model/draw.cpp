#include "model.h"

using namespace		mod1_engine_gl;

void				model::draw() const
{
	start();
	core::draw(vertex_number);
	stop();
}
