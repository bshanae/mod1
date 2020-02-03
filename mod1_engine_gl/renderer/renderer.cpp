#include "renderer.h"

using namespace			mod1_engine_gl;

						renderer::renderer() :
						camera(core.window_width(), core.window_height(), glm::vec3(MOD1_CAMERA_POSITION)),
						framebuffer(core.window_width(), core.window_height()),
						light_info()
{
	core.set_callback(glfw_callback, this);

	light_info.ambient_intensity = MOD1_LIGHT_AMBIENT_INTENSITY;
	light_info.direct_direction = glm::vec3(MOD1_LIGHT_DIRECT_DIRECTION);
	light_info.direct_intensity = MOD1_LIGHT_DIRECT_INTENSITY;

	main_program.add_shader(shader_type::vertex, MOD1_SOURCE_SHADER_VERTEX);
	main_program.add_shader(shader_type::fragment, MOD1_SOURCE_SHADER_FRAGMENT);
	main_program.link();

	MOD1_CONNECT_UNIFORM(main_program, object_transformation)
	MOD1_CONNECT_UNIFORM(main_program, camera_view)
	MOD1_CONNECT_UNIFORM(main_program, camera_projection)
	MOD1_CONNECT_UNIFORM(main_program, light_ambient_intensity)
	MOD1_CONNECT_UNIFORM(main_program, light_direct_direction)
	MOD1_CONNECT_UNIFORM(main_program, light_direct_intensity)

	blur_program.add_shader(shader_type::vertex, "./source_gl/blur_vertex.glsl");
	blur_program.add_shader(shader_type::fragment, "./source_gl/blur_fragment.glsl");
	blur_program.link();

	MOD1_CONNECT_UNIFORM(blur_program, texture)

	blur_square.build();
	blur_square.load();

	FT_Library		ft;
	FT_Face			face;

	if (FT_Init_FreeType(&ft))
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

	if (FT_New_Face(ft, "GillSans.ttc", 0, &face))
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
	FT_Set_Pixel_Sizes(face, 0, 48);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction

	for (GLubyte c = 0; c < 128; c++)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
			continue;
		}

		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
		);

//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Character character = {
			texture,
			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			(unsigned int)face->glyph->advance.x
		};
		Characters.insert(std::pair<char, Character>(c, character));
	}

	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	text_program.add_shader(shader_type::vertex, "./source_gl/text_vertex.glsl");
	text_program.add_shader(shader_type::fragment, "./source_gl/text_fragment.glsl");
	text_program.link();

	MOD1_CONNECT_UNIFORM(text_program, texture)
	MOD1_CONNECT_UNIFORM(text_program, color)
	MOD1_CONNECT_UNIFORM(text_program, projection)

	auto			temp = glm::ortho(0.f, static_cast<float>(core.window_width()), 0.f, static_cast<float>(core.window_height()));

	text_program.start();
	text_program.texture.upload((int)0);
	text_program.color.upload(glm::vec3(1, 0, 0));
	text_program.projection.upload(temp);
	program::stop();

	text_square.set_as_dynamic();
	text_square.build();
	text_square.load();
}