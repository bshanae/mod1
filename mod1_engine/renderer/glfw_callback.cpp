#include "renderer.h"

using namespace			mod1_engine;

void					renderer::glfw_callback(GLFWwindow* window, int key, int code, int action, int mode)
{
	renderer			*renderer;
	static bool			mod_line = false;
	static bool			mod_light = false;

	renderer = (class renderer *)glfwGetWindowUserPointer(window);
	if (key == GLFW_KEY_ESCAPE)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		return ;
	}
	else if (key == GLFW_KEY_A)
		renderer->camera.move(
			camera::mod1_axis_x, camera::mod1_negative,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_D)
		renderer->camera.move(
			camera::mod1_axis_x, camera::mod1_positive,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_W)
		renderer->camera.move(
			camera::mod1_axis_z, camera::mod1_negative,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_S)
		renderer->camera.move(
			camera::mod1_axis_z, camera::mod1_positive,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_Q)
		renderer->camera.move(
			camera::mod1_axis_y, camera::mod1_positive,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_E)
		renderer->camera.move(
			camera::mod1_axis_y, camera::mod1_negative,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_LEFT)
		renderer->camera.rotate(camera::mod1_axis_y, camera::mod1_positive);
	else if (key == GLFW_KEY_RIGHT)
		renderer->camera.rotate(camera::mod1_axis_y, camera::mod1_negative);
	else if (key == GLFW_KEY_UP)
		renderer->camera.rotate(camera::mod1_axis_x, camera::mod1_positive);
	else if (key == GLFW_KEY_DOWN)
		renderer->camera.rotate(camera::mod1_axis_x, camera::mod1_negative);
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
	else
		return ;
	renderer->request_render();
}