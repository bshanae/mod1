#pragma once

#include "gui/namespace.h"

#include "gui/label/label.h"
#include "gui/button/button.h"

class					mod1_gui::layout
{
	friend class 		system;

public :

						layout() = default;
						~layout() = default;

	void				push(label *label);

	void 				activate();
	void 				deactivate();

private :

#define DATA			std::vector<label *>
    DATA				data;
};


