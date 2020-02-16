#include "system.h"

using namespace		mod1_gui;

void				system::callback(void *ptr, const mod1_engine_gl::event &event)
{
	auto			*system = (mod1_gui::system *)ptr;

	for (const button *button : system->button_vector)
		button->test(event);
}