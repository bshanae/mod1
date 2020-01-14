#include "renderer.h"

using namespace			mod1_engine;

void					renderer::load_model(model *model)
{
	model->load(loader);
	model_array.push_back(model);
}