#include "mod1_renderer.h"

						mod1_renderer::mod1_renderer()
{
	core.set_callback(callback, this);
}

void					mod1_renderer::callback(GLFWwindow* window, int key, int code, int action, int mode)
{
	mod1_renderer		*renderer;

	renderer = (mod1_renderer *)glfwGetWindowUserPointer(window);
	if (action == GLFW_RELEASE && key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GL_TRUE);
	else if (action == GLFW_RELEASE && key == GLFW_KEY_ENTER)
		renderer->render_request = true;
}

void					mod1_renderer::load_model(mod1_model *model)
{
	model->load(loader);
	model_array.push_back(model);
}

void 					mod1_renderer::prepare()
{
//	glEnable(GL_DEPTH_TEST);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.f, 0.f, 1.f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void 					mod1_renderer::render()
{
	prepare();
	program.start();
	for (auto &model : model_array)
	{
		model->use();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
	program.stop();
	render_request = false;
	core.swap_buffers();
}

void 				mod1_renderer::loop()
{
	while(!core.is_working())
	{
		glfwPollEvents();

		if (render_request)
			render();
	}
}