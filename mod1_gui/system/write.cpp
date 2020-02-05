#include "system.h"

using namespace		mod1_gui;

void				system::write(const std::string &text, const point2<int> &position)
{
	point2<int>		position_iterator = position;
	point2<int>		position_single;
	symbol			*symbol;

	mod1_engine_gl::core::show_polygon_back(true);

	for (const auto &text_iterator : text)
	{
		symbol = symbol_map[text_iterator];

		position_single.x = position_iterator.x + symbol->bearing().x;
		position_single.y = position_iterator.y - symbol->size().y;

		float		raw[] =
		{
			(float)position_single.x, (float)position_single.y + symbol->size().y, 0,
			(float)position_single.x, (float)position_single.y, 0,
			(float)position_single.x + symbol->size().x, (float)position_single.y + symbol->size().y, 0,
			(float)position_single.x + symbol->size().x, (float)position_single.y, 0
		};

		square.buffer_point.copy(raw);
		square.update(mod1_engine_gl::model_slot::point);

		program.start();
		symbol->texture()->bind();
		mod1_engine_gl::texture::activate();
		square.draw();
		mod1_engine_gl::texture::unbind();
		mod1_engine_gl::program::stop();

		position_iterator.x += symbol->advance();
	}

	mod1_engine_gl::core::show_polygon_back(false);
}