#include "general.h"

void						general::hint_launch(hint_config &config)
{
	if (not config.state_ever)
		config.state_ever = true;
	else
		return ;
	config.state_now = true;

	hint_mod = true;
	hint_last_time = 0;
	hint_remain = hint_timeout;

	hint_label->change_text(config.text);
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

	system.render(hint_layout, false);
}