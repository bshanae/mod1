#include "model.h"

using namespace		mod1_engine_gl;

void				model::update(const model_slot &slot)
{
	if (not MOD1_INTERNAL(is_dynamic))
		throw (exception_dynamic_b());

	switch (slot)
	{
		case model_slot::point :
			vbo_point->buffer(buffer_point, true);
			break ;
		case model_slot::normal :
			vbo_normal->buffer(buffer_normal, true);
			break ;
		case model_slot::color :
			vbo_color->buffer(buffer_color, true);
			break ;
		case model_slot::texture :
			vbo_texture->buffer(buffer_texture, true);
			break ;
		default :
			throw (exception_enum());
	}
}