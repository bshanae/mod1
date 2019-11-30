#include "mod1_core.h"

mod1_core::mod1_core(const mod1_error &error) :
					error(error)
{
	static int 		count;

	if (count++ > 0)
		error.raise_error("Core : Can't initialize more than one object");

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(window_height, window_width, window_name.c_str(), nullptr, nullptr);
	error.test_critical(window != nullptr, "Core : Can't create window");
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	error.test_critical(glewInit() == GLEW_OK, "Core : Can't init GLEW");

	int				width;
	int 			height;

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
}

mod1_core::~mod1_core()
{
	glfwTerminate();
}

GLFWwindow*			mod1_core::get_window() const
{
	return (window);
}