#include "mod1_core.h"

					mod1_core::mod1_core()
{
	static int 		count;

	if (count++ > 0)
		global_error->raise_error("Core : Can't initialize more than one object");

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(window_width_internal, window_height_internal, window_name.c_str(), nullptr, nullptr);
	global_error->test_critical(window != nullptr, "Core : Can't create window");
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	global_error->test_critical(glewInit() == GLEW_OK, "Core : Can't init GLEW");

	int				width;
	int 			height;

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

					mod1_core::~mod1_core()
{
	glfwTerminate();
}

bool				mod1_core::is_working()
{
	return (glfwWindowShouldClose(window));
}

int					mod1_core::window_width()
{
	return (window_width_internal);
}

int					mod1_core::window_height()
{
	return (window_height_internal);
}

void				mod1_core::update()
{
	glfwPollEvents();
}

void				mod1_core::swap_buffers()
{
	glfwSwapBuffers(window);
}

void				mod1_core::set_callback(mod1_callback function, void *ptr)
{
	static int 		count;

	if (count++ > 0)
		global_error->raise_error("Core : Can't have more than one callback");

	glfwSetWindowUserPointer(window, ptr);
	glfwSetKeyCallback(window, function);
}