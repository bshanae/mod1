#include "font.h"

using namespace		mod1_gui;

MOD1_GENERATE_EXCEPTION_DEFINITION(font, exception_freetype)
MOD1_GENERATE_EXCEPTION_DEFINITION(font, exception_font)

					font::font(const std::string &source, const int &width)
{
	if (FT_Init_FreeType(&library))
		throw (exception_freetype());

	if (FT_New_Face(library, source.c_str(), 0, &face))
		throw (exception_font());

	FT_Set_Pixel_Sizes(face, 0, width);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

					font::~font()
{
	FT_Done_Face(face);
	FT_Done_FreeType(library);
}
