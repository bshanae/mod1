#include "mod1_renderer.h"

						mod1_renderer::mod1_renderer()
{
	core.set_callback(callback, this);
	camera_position = glm::vec3(0.0f, 0.0f, -2.0f);
	matrix_view = glm::mat4(1.0f);
	matrix_projection = glm::perspective(
		glm::radians(45.0f),
		(float)core.window_width / (float)core.window_height,
		0.1f,
		100.0f);
	uniform_transformation = glGetUniformLocation(program.object(), "transformation");
}

void					mod1_renderer::callback(GLFWwindow* window, int key, int code, int action, int mode)
{
	mod1_renderer		*renderer;

	renderer = (mod1_renderer *)glfwGetWindowUserPointer(window);
	if (key == GLFW_KEY_ESCAPE)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		return ;
	}
	else if (key == GLFW_KEY_A)
		renderer->camera_position.x += renderer->camera_step;
	else if (key == GLFW_KEY_D)
		renderer->camera_position.x -= renderer->camera_step;
	else if (key == GLFW_KEY_W)
		renderer->camera_position.z += renderer->camera_step;
	else if (key == GLFW_KEY_S)
		renderer->camera_position.z -= renderer->camera_step;
	else if (key == GLFW_KEY_Q)
		renderer->camera_position.y -= renderer->camera_step;
	else if (key == GLFW_KEY_E)
		renderer->camera_position.y += renderer->camera_step;
	else
		return ;
	renderer->render();
}

void					mod1_renderer::load_model(mod1_model *model)
{
	model->load(loader);
	model_array.push_back(model);
}

void 					mod1_renderer::internal_prepare()
{
//	glEnable(GL_DEPTH_TEST);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.f, 0.f, 1.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	matrix_view = glm::translate(glm::mat4(1.0f), camera_position);
	glm::mat4 temp = glm::translate(matrix_projection, camera_position);
	glUniformMatrix4fv(uniform_transformation, 1, GL_FALSE, glm::value_ptr(matrix_projection * matrix_view));
}

void 					mod1_renderer::internal_render()
{
	program.start();
	internal_prepare();
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
			internal_render();
	}
}