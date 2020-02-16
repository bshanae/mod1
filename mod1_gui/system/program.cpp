#include "system.h"

					mod1_gui::system::program::program(const mod1_engine_gl::core &core)
{
	add_shader(mod1_engine_gl::shader_type::vertex, MOD1_GUI_PROGRAM_TEXT_VERTEX);
	add_shader(mod1_engine_gl::shader_type::fragment, MOD1_GUI_PROGRAM_TEXT_FRAGMENT);
	link();

	MOD1_CONNECT_UNIFORM(*this, texture)
	MOD1_CONNECT_UNIFORM(*this, color)
	MOD1_CONNECT_UNIFORM(*this, projection)

	auto			temp = glm::ortho(
		0.f,
		(float)core.window_width(),
		(float)core.window_height(),
		0.f);

	start();
	texture.upload((int)0);
	color.upload(glm::vec3(1, 0, 0));
	projection.upload(temp);
	program::stop();
}