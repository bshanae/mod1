#pragma once

#include "mod1_gui/namespace.h"

#include "mod1_gui/symbol/symbol.h"
#include "mod1_gui/font/font.h"
#include "mod1_gui/button/button.h"

class									mod1_gui::system
{
public :
	explicit							system(mod1_engine_gl::core &core);
										~system();

	void								render();

	void 								add_button(
										const int &center_x,
										const int &center_y,
										const std::string &text,
										callback_functor functor,
										void *ptr = nullptr);
	void 								add_button(
										const point2<int> &center,
										const std::string &text,
										callback_functor functor,
										void *ptr = nullptr);

	void								write(const std::string &text, const point2<int> &position);

private :

	class								square : public mod1_engine_gl::model
	{
	public :

										square();

		void							build() override;

		using							model::save;

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

	std::vector<button>					button_vector;

	void								render(const button &button);

	static void							callback(const mod1_engine_gl::event &event, void *ptr);
};


