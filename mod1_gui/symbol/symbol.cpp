#include "symbol.h"

using namespace		mod1_gui;

MOD1_GENERATE_INTERNAL_READ_DEFINITION(symbol, texture)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(symbol, size)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(symbol, bearing)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(symbol, advance)

					symbol::symbol(FT_Face &face)
{
	MOD1_INTERNAL(texture) = new mod1_engine_gl::texture(mod1_engine_gl::texture_type::custom);

	MOD1_INTERNAL(texture)->bind();
	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RED,
		face->glyph->bitmap.width, face->glyph->bitmap.rows,
		0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	MOD1_INTERNAL(size) = mod1_engine_gl::point2<int>(face->glyph->bitmap.width, face->glyph->bitmap.rows);
	MOD1_INTERNAL(bearing) = mod1_engine_gl::point2<int>(face->glyph->bitmap_left, face->glyph->bitmap_top);
	MOD1_INTERNAL(advance) = face->glyph->advance.x;
}

					symbol::~symbol()
{
	delete MOD1_INTERNAL(texture);
}