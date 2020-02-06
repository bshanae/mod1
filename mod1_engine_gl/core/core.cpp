#include "core.h"

using namespace		mod1_engine_gl;

MOD1_GENERATE_EXCEPTION_DEFINITION(core, exception_logic_object)
MOD1_GENERATE_EXCEPTION_DEFINITION(core, exception_window)
MOD1_GENERATE_EXCEPTION_DEFINITION(core, exception_GLEW)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(core, window_width)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(core, window_height)


GLFWwindow			*global_window = nullptr;
bool				global_signal_block = false;

					core::core()
{
	static int 		count;

MOD1_GENERATE_MESSAGE("")

	if (count++ > 0)
		throw (exception_logic_object());

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

MOD1_GENERATE_MESSAGE("Mod1 Engine GL, Core : GLFW Launched")

	window = glfwCreateWindow(
		MOD1_INTERNAL(window_width),
		MOD1_INTERNAL(window_height),
		window_name.c_str(),
		nullptr, nullptr);
	if (!window)
		throw (exception_window());
	global_window = window;

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw (exception_GLEW());

MOD1_GENERATE_MESSAGE("Mod1 Engine GL, Core : GLEW Launched")

	int				width;
	int 			height;

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	MOD1_INTERNAL(window_width) = width;
	MOD1_INTERNAL(window_height) = height;

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glProvokingVertex(GL_FIRST_VERTEX_CONVENTION);
	glEnable(GL_DEPTH_TEST);

MOD1_GENERATE_MESSAGE("Mod1 Engine GL, Core : OpenGL is set")

#if MOD1_ENABLED(MOD1_SRGB)
	glEnable(GL_FRAMEBUFFER_SRGB);
#endif

	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, glfw_callback_key);
	glfwSetMouseButtonCallback(window, glfw_callback_mouse_key);
	glfwSetCursorPosCallback(window, glfw_callback_mouse_movement);

MOD1_GENERATE_MESSAGE("Mod1 Engine GL, Core : Event system is set")

	double			x;
	double			y;

	glfwGetCursorPos(window, &x, &y);
	event.mouse = point2<int>(x, y);

	show_polygon_back(false);

MOD1_GENERATE_MESSAGE("Mod1 Engine GL, Core : Ready")
}

					core::~core()
{
	glfwTerminate();
	global_window = nullptr;
}