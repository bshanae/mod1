#include "system.h"

using namespace		mod1_gui;

void				system::write(
					const point2<int> &position,
					const std::string &text,
					const font *font)
{
	point2<int>		position_iterator = position;
	point2<int>		position_single;
	const symbol	*symbol;

	mod1_engine_gl::core::show_polygon_back(true);
	mod1_engine_gl::core::use_depth_test(false);

	program.start();

	program.color.upload(font->color.glm());

	for (const auto &text_iterator : text)
	{
		symbol = font->find_symbol(text_iterator);

		position_single.x = position_iterator.x + symbol->bearing().x;
		position_single.y = position_iterator.y - symbol->bearing().y;

		float		raw[] =
		{
			(float)position_single.x, (float)position_single.y + symbol->size().y, 0,
			(float)position_single.x, (float)position_single.y, 0,
			(float)position_single.x + symbol->size().x, (float)position_single.y + symbol->size().y, 0,
			(float)position_single.x + symbol->size().x, (float)position_single.y, 0
		};

		square.buffer_point.copy(raw);
		square.save(mod1_engine_gl::model_slot::point);

		symbol->texture()->bind();
		mod1_engine_gl::texture::activate();
		square.draw();
		mod1_engine_gl::texture::unbind();

		position_iterator.x += symbol->advance();
	}

	mod1_engine_gl::program::stop();

	mod1_engine_gl::core::show_polygon_back(false);
	mod1_engine_gl::core::use_depth_test(true);
}