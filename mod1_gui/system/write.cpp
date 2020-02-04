#include "system.h"

using namespace		mod1_gui;

void				system::write(const std::string &text, const point2<int> &position)
{
	point2<int>		position_iterator = position;
	point2<int>		position_single;
	symbol			*symbol;

	for (const auto &text_iterator : text)
	{
		symbol = symbol_map[text_iterator];

		position_single.x = position_iterator.x + symbol->bearing().x;
		position_single.y = position_iterator.y - (symbol->size().y - symbol->bearing().y);

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

		position_iterator.x += (static_cast<unsigned int>(symbol->advance()) >> 6u);
	}
/*
	symbol *symbol = symbol_map['j'];

#define X_START				100.f
#define Y_START				100.f

#define X_EXTEND			symbol->size().x
#define Y_EXTEND			symbol->size().y

	float			array[] = {
		X_START, Y_START, 0,
		X_START, Y_START + Y_EXTEND, 0,
		X_START + X_EXTEND, Y_START, 0,
		X_START + X_EXTEND, Y_START + Y_EXTEND, 0
	};

	square.buffer_point.copy(array);
	square.update(mod1_engine_gl::model_slot::point);

	program.start();
	symbol->texture()->bind();
	mod1_engine_gl::texture::activate();
	square.draw();
	mod1_engine_gl::texture::unbind();
	mod1_engine_gl::program::stop();
 */
}