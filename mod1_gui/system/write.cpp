#include "system.h"

using namespace		mod1_gui;

void				system::write(const std::string &text)
{
//	for (const auto &iter : text)

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
}