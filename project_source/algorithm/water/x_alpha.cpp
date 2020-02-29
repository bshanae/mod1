#include "water.h"

using namespace			mod1_algorithm;


void					water::set_alpha(const float &alpha)
{
	color_alpha = alpha;
}

void					water::set_alpha(const int &alpha)
{
	set_alpha((float)alpha / 255.f);
}
