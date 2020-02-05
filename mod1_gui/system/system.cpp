#include "system.h"

using namespace		mod1_gui;

					system::system(mod1_engine_gl::core &core) :
					program(core)
{
	for (int i = 0; i < 128; i++)
		symbol_map.emplace(i, font.generate_symbol(static_cast<char>(i)));

	core.add_callback(mod1_engine_gl::event_type::mouse_press, callback, this);
}
					system::~system()
{
	for (const auto &[key, value] : symbol_map)
		delete value;
}