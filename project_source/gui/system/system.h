#pragma once

#include "gui/namespace.h"

#include "gui/symbol/symbol.h"
#include "gui/font/font.h"
#include "gui/label/label.h"
#include "gui/button/button.h"
#include "gui/layout/layout.h"

class						mod1_gui::system
{
public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_symbol, "Mod1 GUI, System : Symbol not found")

	explicit				system(mod1_engine_gl::core &core);
							~system();

	void					render(const layout &layout, const bool &swap = true);

	label		 			*generate_label(
							const int &center_x,
							const int &center_y,
							const std::string &text,
							const font *font);
	label		 			*generate_label(
							const point2<int> &center,
							const std::string &text,
							const font *font);

	button		 			*generate_button(
							const int &center_x,
							const int &center_y,
							const std::string &text,
							const font *font,
							functor_ptr functor,
							void *ptr = nullptr);
	button		 			*generate_button(
							const point2<int> &center,
							const std::string &text,
							const font *font,
							functor_ptr functor,
							void *ptr = nullptr);

	void					write(
							const point2<int> &position,
							const std::string &text,
							const font *font);

private :

	class					square : public mod1_engine_gl::model
	{
	public :

							square();

		void				build() override;

		using				model::save;

		using				model::buffer_point;
		using				model::buffer_texture;
	}						square;

	class					program : public mod1_engine_gl::program
	{
	public :
		explicit			program(const mod1_engine_gl::core &core);

	MOD1_GENERATE_UNIFORM(texture, "uniform_texture")
	MOD1_GENERATE_UNIFORM(color, "uniform_color")
	MOD1_GENERATE_UNIFORM(projection, "uniform_projection")
	}						program;

	std::vector<label *>	label_vector;
	std::vector<button *>	button_vector;

	void					render(const label &label);

	static void				callback(void *ptr, const mod1_engine_gl::event &event);
};


