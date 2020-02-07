#include "plane.h"

using namespace			mod1_algorithm;

void					plane::define_alpha(const float &alpha)
{
	color_alpha = alpha;
}

void					plane::define_alpha(const int &alpha)
{
	define_alpha((float)alpha / 255.f);
}