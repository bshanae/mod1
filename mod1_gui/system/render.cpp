#include "system.h"

using namespace		mod1_gui;

void				system::render()
{
	for (const auto &button : button_vector)
		render(button);
}

void				system::render(const button &button)
{
	point2<int>		start;

	start.x = button.center().x - button.size().x / 2;
	start.y = button.center().y;
	write(button.text(), start);
}
