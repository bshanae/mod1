#include "mod1_renderer.h"

						mod1_renderer::mod1_renderer() :
						camera(core.window_width(), core.window_height(), camera_position)
{
	core.set_callback(glfw_callback, this);

	light_position = glm::vec3(0, 100, 0);

	uniform_view = glGetUniformLocation(program.object(), "view");
	uniform_projection = glGetUniformLocation(program.object(), "projection");
	glUniformMatrix4fv(uniform_projection, 1, GL_FALSE, glm::value_ptr(camera.projection));
	uniform_light = glGetUniformLocation(program.object(), "light_position");
}

#define M1				2

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
	{
		if (!mod_light)
			renderer->camera.move(mod1_camera::mod1_axis_x,  mod1_camera::mod1_negative);
		else
			renderer->light_position.x -= M1;
	}
	else if (key == GLFW_KEY_D)
	{
		if (!mod_light)
			renderer->camera.move(mod1_camera::mod1_axis_x,  mod1_camera::mod1_positive);
		else
			renderer->light_position.x += M1;
	}
	else if (key == GLFW_KEY_W)
	{
		if (!mod_light)
			renderer->camera.move(mod1_camera::mod1_axis_z,  mod1_camera::mod1_negative);
		else
			renderer->light_position.z -= M1;
	}
	else if (key == GLFW_KEY_S)
	{
		if (!mod_light)
			renderer->camera.move(mod1_camera::mod1_axis_z,  mod1_camera::mod1_positive);
		else
			renderer->light_position.z += M1;
	}
	else if (key == GLFW_KEY_Q)
	{
		if (!mod_light)
			renderer->camera.move(mod1_camera::mod1_axis_y,  mod1_camera::mod1_positive);
		else
			renderer->light_position.y += M1;
	}
	else if (key == GLFW_KEY_E)
	{
		if (!mod_light)
			renderer->camera.move(mod1_camera::mod1_axis_y,  mod1_camera::mod1_negative);
		else
			renderer->light_position.y -= M1;
	}
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
	glUniform3f(uniform_light, light_position.x, light_position.y, light_position.z);
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