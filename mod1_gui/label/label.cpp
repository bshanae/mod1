#include "label.h"

using namespace		mod1_gui;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(label, center)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(label, size)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(label, text)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(label, font)

					label::label(
					const point2<int> &center,
					const std::string &text,
					const class font *font) :
					MOD1_INTERNAL(center)(center),
					MOD1_INTERNAL(font)(font)
{
	change_text(text);
}

void 				label::change_position(const point2<int> &center)
{
	MOD1_INTERNAL(center) = center;
}

void 				label::change_text(const std::string &text)
{
	const symbol	*symbol;

	MOD1_INTERNAL(text) = text;
	MOD1_INTERNAL(size) = point2<int>();

	for (const char &iter : text)
	{
		symbol = MOD1_INTERNAL(font)->find_symbol(iter);

		MOD1_INTERNAL(size).x += symbol->advance();
		MOD1_INTERNAL(size).y = MOD1_MAX(MOD1_INTERNAL(size).y, symbol->size().y);
	}
}
