#include "system.h"

using namespace		mod1_gui;

void				system::callback(const mod1_engine_gl::event &event, void *ptr)
{
	auto			*system = (mod1_gui::system *)ptr;

	for (const button &button : system->button_vector)
		button.test(event);
}