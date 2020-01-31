#include "renderer.h"

using namespace			mod1_engine_gl;

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
		glBindFramebuffer(GL_FRAMEBUFFER, renderer->framebuffer);
//		renderer->framebuffer.start();

		renderer->core.clear(point3<float>(0, 0, 1));

		renderer->render_no_swap();
//		renderer->framebuffer.stop();
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		renderer->blur_program.start();

		renderer->loader.vao_bind(renderer->blur_vao);
//		renderer->framebuffer.texture()->start();
		glActiveTexture(GL_TEXTURE0 + 1);
		glBindTexture(GL_TEXTURE_2D, renderer->texture_color);

		glUniform1i(glGetUniformLocation(renderer->blur_program.object(), "uniform_texture"), 1);

		renderer->core.draw_arrays(6);

//		renderer->framebuffer.texture()->stop();
		glBindTexture(GL_TEXTURE_2D, renderer->texture_color);
		renderer->loader.vao_unbind();
		renderer->blur_program.stop();

		renderer->core.swap_buffers();
		return ;
	}
	else if (key == GLFW_KEY_6 && action == GLFW_PRESS)
	{
		renderer->render_internal();
	}
	else
		return ;
//	renderer->render();
	renderer->render_internal();
}