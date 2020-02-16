#include "system.h"

using namespace		mod1_gui;

MOD1_GENERATE_EXCEPTION_DEFINITION(system, exception_symbol)

					system::system(mod1_engine_gl::core &core) :
					program(core)
{
MOD1_GENERATE_MESSAGE("")

	for (int i = 0; i < 128; i++)
		symbol_map.emplace(i, font.generate_symbol(static_cast<char>(i)));

MOD1_GENERATE_MESSAGE("Mod1 GUI, System : Font is prepared")

	core.add_callback(mod1_engine_gl::event_type::mouse_press, callback, this);

MOD1_GENERATE_MESSAGE("Mod1 GUI, System : Ready")
}
					system::~system()
{
	for (const auto &[key, value] : symbol_map)
		delete value;
	for (button *button : button_vector)
		delete button;
}