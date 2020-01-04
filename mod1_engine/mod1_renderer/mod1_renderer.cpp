#include "mod1_renderer.h"

						mod1_renderer::mod1_renderer() :
						camera(core.window_width(), core.window_height(), camera_position)
{
	core.set_callback(glfw_callback, this);

	light_info.ambient_intensity = 0.3;
	light_info.point_position = glm::vec3(0, 100, 0);
	light_info.point_intensity = 0.8;
	light_info.point_power = 2.;

	uniform_view = glGetUniformLocation(program.object(), "view");
	uniform_projection = glGetUniformLocation(program.object(), "projection");
	glUniformMatrix4fv(uniform_projection, 1, GL_FALSE, glm::value_ptr(camera.projection));
	uniform_light_ambient_intensity = glGetUniformLocation(program.object(), "light_info.ambient_intensity");
	uniform_light_point_position = glGetUniformLocation(program.object(), "light_info.point_position");
	uniform_light_point_intensity = glGetUniformLocation(program.object(), "light_info.point_intensity");
	uniform_light_point_power = glGetUniformLocation(program.object(), "light_info.point_power");
}

void					mod1_renderer::glfw_callback(GLFWwindow* window, int key, int code, int action, int mode)
{
	mod1_renderer		*renderer;
	static bool			mod_line = false;
	static bool			mod_light = false;

	renderer = (mod1_renderer *)glfwGetWindowUserPointer(window);
	for (const auto &callback : renderer->callback_array)
		if (callback.run(key))
			renderer->render();
	if (key == GLFW_KEY_ESCAPE)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		return ;
	}
	else if (key == GLFW_KEY_A)
		renderer->camera.move(
			mod1_camera::mod1_axis_x, mod1_camera::mod1_negative,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_D)
		renderer->camera.move(
			mod1_camera::mod1_axis_x, mod1_camera::mod1_positive,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_W)
		renderer->camera.move(
			mod1_camera::mod1_axis_z, mod1_camera::mod1_negative,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_S)
		renderer->camera.move(
			mod1_camera::mod1_axis_z, mod1_camera::mod1_positive,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_Q)
		renderer->camera.move(
			mod1_camera::mod1_axis_y, mod1_camera::mod1_positive,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_E)
		renderer->camera.move(
			mod1_camera::mod1_axis_y, mod1_camera::mod1_negative,
			mod_light ? &renderer->light_info.point_position : nullptr);
	else if (key == GLFW_KEY_LEFT)
		renderer->camera.rotate(mod1_camera::mod1_axis_y, mod1_camera::mod1_positive);
	else if (key == GLFW_KEY_RIGHT)
		renderer->camera.rotate(mod1_camera::mod1_axis_y, mod1_camera::mod1_negative);
	else if (key == GLFW_KEY_UP)
		renderer->camera.rotate(mod1_camera::mod1_axis_x, mod1_camera::mod1_positive);
	else if (key == GLFW_KEY_DOWN)
		renderer->camera.rotate(mod1_camera::mod1_axis_x, mod1_camera::mod1_negative);
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
	renderer->render();
}

void					mod1_renderer::add_callback(mod1_callback::functor_type functor, void *ptr)
{
	callback_array.emplace_back(mod1_callback(functor, ptr));
}

void					mod1_renderer::load_model(mod1_model *model)
{
	model->load(loader);
	model_array.push_back(model);
}

void 					mod1_renderer::prepare_internal()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUniformMatrix4fv(uniform_view, 1, GL_FALSE, glm::value_ptr(camera.view()));
	glUniform1f(uniform_light_ambient_intensity, light_info.ambient_intensity);
	glUniform3f(uniform_light_point_position, light_info.point_position.x, light_info.point_position.y, light_info.point_position.z);
	glUniform1f(uniform_light_point_intensity, light_info.point_intensity);
	glUniform1f(uniform_light_point_power, light_info.point_power);
}

void 					mod1_renderer::render_internal()
{
	program.start();
	prepare_internal();
	for (auto &model : model_array)
	{
		model->use();
		glDrawElements(GL_TRIANGLES, model->vertex_number(), GL_UNSIGNED_INT, nullptr);
	}
	program.stop();
	core.swap_buffers();
	render_request = false;
}

void					mod1_renderer::render()
{
	render_request = true;
}

void 					mod1_renderer::loop()
{
	while(!core.is_working())
	{
		core.update();
		if (render_request)
			render_internal();
	}
}