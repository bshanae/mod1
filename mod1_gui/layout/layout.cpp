#include "layout.h"

using namespace		mod1_gui;

void				layout::push(label *label)
{
	data.push_back(label);
}

void 				layout::activate()
{
	button			*button;

	for (label *label : data)
		if ((button = dynamic_cast<class button *>(label)) != nullptr)
			button->activate();

}
void 				layout::deactivate()
{
	button			*button;

	for (label *label : data)
		if ((button = dynamic_cast<class button *>(label)) != nullptr)
			button->deactivate();
}