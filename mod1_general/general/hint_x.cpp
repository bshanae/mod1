#include "general.h"

void						general::hint_init(
							const std::string &text)
{
	hint_mod = true;
	hint_text = text;

	hint_last_time = 0;
	hint_remain = hint_timeout;

	point2<int>				size;
	const mod1_gui::symbol	*symbol;

	for (const char &iter : text)
	{
		symbol = hint_font->find_symbol(iter);

		size.x += symbol->advance();
		size.y = MOD1_MAX(size.y, symbol->size().y);
	}

	hint_position.x = hint_center.x - size.x / 2;
	hint_position.y = hint_center.y + size.y / 2;
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