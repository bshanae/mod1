#include "general.h"

void						general::hint_init(
							const int &center_x,
							const int &center_y,
							const std::string &text,
							const mod1_gui::font *font,
							const double &timeout)
{
	hint_mod = true;
	hint_text = text;

	hint_last_time = 0;
	hint_remain = timeout;

	point2<int>				size;
	const mod1_gui::symbol	*symbol;

	for (const char &iter : text)
	{
		symbol = font->find_symbol(iter);

		size.x += symbol->advance();
		size.y = MOD1_MAX(size.y, symbol->size().y);
	}

	hint_position.x = center_x - size.x / 2;
	hint_position.y = center_y + size.y / 2;
}

void 						general::hint_render()
{
	const double 			time = core::time();

	if (not hint_mod)
		return ;

	hint_remain -= hint_last_time == 0 ? 0 : time - hint_last_time;
	hint_last_time = time;

	if (hint_remain < 0)
		hint_mod = false;

	system.write(hint_position, hint_text, font_gill_sans);
}