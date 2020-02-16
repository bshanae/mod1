#include "layout.h"

using namespace		mod1_gui;

void				layout::push(button *button)
{
	data.push_back(button);
}

void 				layout::activate()
{
	for (button *iter : data)
		iter->activate();

}
void 				layout::deactivate()
{
	for (button *iter : data)
		iter->deactivate();
}