#include "renderer.h"

using namespace			mod1_engine_gl;

void					RenderText(renderer *renderer, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color)
{
	// Activate corresponding render state
	renderer->text_program.start();
	glUniform3f(glGetUniformLocation(renderer->text_program.object(), "uniform_color"), color.x, color.y, color.z);
	glActiveTexture(GL_TEXTURE0);
//	glUniform1i(glGetUniformLocation(renderer->text_program.object(), "uniform_texture"), 0);
	glBindVertexArray(renderer->text_VAO);

	// Iterate through all characters
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = renderer->Characters[*c];

		GLfloat xpos = x + ch.bearing.x * scale;
		GLfloat ypos = y - (ch.size.y - ch.bearing.y) * scale;

		GLfloat w = ch.size.x * scale;
		GLfloat h = ch.size.y * scale;
		// Update VBO for each character
		GLfloat vertices[6][4] = {
			{ xpos, ypos + h, 0.0, 0.0 },
			{ xpos, ypos, 0.0, 1.0 },
			{ xpos + w, ypos, 1.0, 1.0 },
			{ xpos, ypos + h, 0.0, 0.0 },
			{ xpos + w, ypos, 1.0, 1.0 },
			{ xpos + w, ypos + h, 1.0, 0.0 }
		};
		// Render glyph texture over quad
		glBindTexture(GL_TEXTURE_2D, ch.textureID);
		// Update content of VBO memory
		glBindBuffer(GL_ARRAY_BUFFER, renderer->text_VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// Render quad
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += (ch.advance >> 6u) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void					renderer::glfw_callback(GLFWwindow* window, int key, int code, int action, int mode)
{
	renderer			*renderer;
	static bool			mod_line = false;
	static bool			mod_light = false;

	renderer = (mod1_engine_gl::renderer *)glfwGetWindowUserPointer(window);
	for (const auto &callback : renderer->callback_array)
		if (callback.run(key))
			renderer->render();
	if (key == GLFW_KEY_ESCAPE)
	{
		renderer->terminate();
		return ;
	}
	else if (key == GLFW_KEY_A)
		renderer->camera.move(axis::x, sign::negative);
	else if (key == GLFW_KEY_D)
		renderer->camera.move(axis::x, sign::positive);
	else if (key == GLFW_KEY_W)
		renderer->camera.move(axis::z, sign::negative);
	else if (key == GLFW_KEY_S)
		renderer->camera.move(axis::z, sign::positive);
	else if (key == GLFW_KEY_Q)
		renderer->camera.move(axis::y, sign::positive);
	else if (key == GLFW_KEY_E)
		renderer->camera.move(axis::y, sign::negative);
	else if (key == GLFW_KEY_LEFT && !mod_light)
		renderer->camera.rotate(axis::y, sign::positive);
	else if (key == GLFW_KEY_RIGHT && !mod_light)
		renderer->camera.rotate(axis::y, sign::negative);
	else if (key == GLFW_KEY_UP && !mod_light)
		renderer->camera.rotate(axis::x, sign::positive);
	else if (key == GLFW_KEY_DOWN && !mod_light)
		renderer->camera.rotate(axis::x, sign::negative);
	else if (key == GLFW_KEY_LEFT && mod_light)
		renderer->camera.rotate(renderer->light_info.direct_direction, axis::y, sign::negative);
	else if (key == GLFW_KEY_RIGHT && mod_light)
		renderer->camera.rotate(renderer->light_info.direct_direction, axis::y, sign::positive);
	else if (key == GLFW_KEY_UP && mod_light)
		renderer->camera.rotate(renderer->light_info.direct_direction, axis::x, sign::negative);
	else if (key == GLFW_KEY_DOWN && mod_light)
		renderer->camera.rotate(renderer->light_info.direct_direction, axis::x, sign::positive);
	else if (key == GLFW_KEY_R && action == GLFW_PRESS)
	{
		mod_line = !mod_line;
		if (mod_line)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else if (key == GLFW_KEY_L && action == GLFW_PRESS)
		mod_light = !mod_light;
	else if (key == GLFW_KEY_5 && action == GLFW_PRESS)
	{
		renderer->framebuffer.bind();
		renderer->render_no_swap();
		framebuffer::unbind();

		renderer->blur_program.start();
		renderer->framebuffer.texture().bind();
		texture::activate();
		renderer->blur_program.texture.upload(0);
		renderer->blur_square.draw();
		texture::unbind();
		renderer->blur_program.stop();

		renderer->core.swap_buffers();
		return ;
	}
	else if (key == GLFW_KEY_6 && action == GLFW_PRESS)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (false)
		{
			std::cout << "Text" << std::endl;
			RenderText(renderer, "This is sample text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));

		}
		else
		{
			GLuint id = renderer->Characters['g'].textureID;

			float			array[] = {
				-0.5, -0.5,
				-0.5, +0.5,
				+0.5, -0.5,
				+0.5, +0.5
			};

//			renderer->text_square.coordinate_buffer.copy(array);
//			renderer->text_square.vbo_coordinate->buffer(renderer->text_square.coordinate_buffer);

			renderer->blur_program.start();
			glBindTexture(GL_TEXTURE_2D, id);
			texture::activate();
			renderer->blur_program.texture.upload(0);
			renderer->text_square.draw();
			glBindTexture(GL_TEXTURE_2D, 0);
			renderer->blur_program.stop();
		}

		renderer->core.swap_buffers();
		return ;
	}
	else
		return ;
	renderer->render();
}