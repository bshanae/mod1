#include "renderer.h"

					::renderer::renderer() :
					mod1_engine_gl::renderer(),
					framebuffer(core.window_width(), core.window_height()),
					program_main(),
					program_blur(),
					program_text(),
					light_info()

{
	light_info.ambient_intensity = MOD1_LIGHT_AMBIENT_INTENSITY;
	light_info.direct_direction = glm::vec3(MOD1_LIGHT_DIRECT_DIRECTION);
	light_info.direct_intensity = MOD1_LIGHT_DIRECT_INTENSITY;

	square_blur.build();
	square_blur.load();

	square_text.set_as_dynamic();
	square_text.build();
	square_text.load();

	add_callback((mod1_engine_gl::callback::functor_type)(::renderer::callback), this);

	mod1_gui::font	font("GillSans.ttc", 48);

	for (int i = 0; i < 128; i++)
	{
		char 		c = static_cast<char>(i);
		symbol_map.emplace(c, font.generate_symbol(c));
	}

	auto			temp = glm::ortho(0.f, static_cast<float>(core.window_width()), 0.f, static_cast<float>(core.window_height()));

	program_text.start();
	program_text.texture.upload((int)0);
	program_text.color.upload(glm::vec3(1, 0, 0));
	program_text.projection.upload(temp);
	program::stop();
}