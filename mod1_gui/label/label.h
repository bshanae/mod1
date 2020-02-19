#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/font/font.h"

class				mod1_gui::label
{
	friend class	system;

public :

	virtual			~label() = default;

	void 			change_position(const point2<int> &center);
	void 			change_text(const std::string &text);

protected :

					label(
					const point2<int> &center,
					const std::string &text,
					const font *font);

MOD1_GENERATE_INTERNAL(point2<int>, center)
MOD1_GENERATE_INTERNAL(point2<int>, size)
MOD1_GENERATE_INTERNAL(std::string, text)
MOD1_GENERATE_INTERNAL(const font *, font)

public :

MOD1_GENERATE_INTERNAL_READ_DECLARATION(center)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(size)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(text)
MOD1_GENERATE_INTERNAL_READ_DECLARATION(font)
};


