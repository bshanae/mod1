#include "system.h"

using namespace		mod1_gui;

void				system::render(const layout &layout)
{
	for (const button *button : layout.data)
		render(*button);
}

void				system::render(const button &button)
{
	point2<int>		start;

	start.x = button.center().x - button.size().x / 2;
	start.y = button.center().y + button.size().y / 2;;
	write(button.text(), start);
}
