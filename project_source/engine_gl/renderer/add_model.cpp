#include "renderer.h"

using namespace			mod1_engine_gl;

void					renderer::add_model(model *model)
{
	if (not model->is_loaded())
		model->load();
	MOD1_INTERNAL(model_array).push_back(model);
}