#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/font/font.h"

class									mod1_gui::system
{
public :
										system(const mod1_engine_gl::core &core);
										~system();

	void								write(const std::string &text);

private :


	class								square : public mod1_engine_gl::model
	{
	public :

										square();

		void							build() override;

		using							model::update;

		using							model::buffer_point;
		using							model::buffer_texture;
	}									square;

	class								program : public mod1_engine_gl::program
	{
	public :
		explicit						program(const mod1_engine_gl::core &core);

	MOD1_GENERATE_UNIFORM(texture, "uniform_texture")
	MOD1_GENERATE_UNIFORM(color, "uniform_color")
	MOD1_GENERATE_UNIFORM(projection, "uniform_projection")
	}									program;


	font								font = mod1_gui::font(MOD1_FONT_SOURCE, MOD1_FONT_WIDTH);
	std::map<char, mod1_gui::symbol *>	symbol_map;
};


