#include "model.h"

using namespace		mod1_engine_gl;

void 				*model::pointer(const int &index, const model_slot &slot)
{
	if (slot == model_slot::point)
		return (&buffer_point[MOD1_MODEL_POINT_GROUP * index]);
	else if (slot == model_slot::index)
		return (&buffer_index[MOD1_MODEL_INDEX_GROUP * index]);
	else if (slot == model_slot::normal)
		return (&buffer_normal[MOD1_MODEL_NORMAL_GROUP * index]);
	else if (slot == model_slot::color)
		return (&buffer_color[MOD1_MODEL_COLOR_GROUP * index]);
	else if (slot == model_slot::texture)
		return (&buffer_texture[MOD1_MODEL_TEXTURE_GROUP * index]);
	else
		throw (exception_enum());
}

void const			*model::pointer(const int &index, const model_slot &slot) const
{
	if (slot == model_slot::point)
		return (&buffer_point[MOD1_MODEL_POINT_GROUP * index]);
	else if (slot == model_slot::index)
		return (&buffer_index[MOD1_MODEL_INDEX_GROUP * index]);
	else if (slot == model_slot::normal)
		return (&buffer_normal[MOD1_MODEL_NORMAL_GROUP * index]);
	else if (slot == model_slot::color)
		return (&buffer_color[MOD1_MODEL_COLOR_GROUP * index]);
	else if (slot == model_slot::texture)
		return (&buffer_texture[MOD1_MODEL_TEXTURE_GROUP * index]);
	else
		throw (exception_enum());
}