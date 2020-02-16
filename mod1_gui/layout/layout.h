#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/button/button.h"

class					mod1_gui::layout
{
	friend class 		system;

public :

						layout() = default;
						~layout() = default;

	void				push(button *button);

	void 				activate();
	void 				deactivate();

private :

#define DATA			std::vector<button *>
    DATA				data;
};


