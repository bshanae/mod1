#include "system.h"

using namespace		mod1_gui;

void				system::render(const layout &layout, const bool &swap)
{
	for (const label *label : layout.data)
		render(*label);
	if (swap)
		mod1_engine_gl::core::swap_buffers();
}

void				system::render(const label &label)
{
	point2<int>		start;

	start.x = label.center().x - label.size().x / 2;
	start.y = label.center().y + label.size().y / 2;
	write(start, label.text(), label.font());
}
