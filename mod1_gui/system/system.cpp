#include "system.h"

using namespace		mod1_gui;

MOD1_GENERATE_EXCEPTION_DEFINITION(system, exception_symbol)

					system::system(mod1_engine_gl::core &core) :
					program(core)
{
MOD1_GENERATE_MESSAGE("")

	core.add_callback(mod1_engine_gl::event_type::mouse_release, callback, this);

MOD1_GENERATE_MESSAGE("Mod1 GUI, System : Ready")
}
					system::~system()
{
	for (button *button : button_vector)
		delete button;
}