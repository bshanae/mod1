#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"
#include "mod1_core.h"
#include "mod1_program.h"
#include "mod1_model.h"
#include "mod1_loader.h"

#include <fstream>
#include <sstream>
#include <cmath>

class							mod1_renderer
{

public :

								mod1_renderer();
								~mod1_renderer() = default;

	void						load_model(mod1_model *model);

	void						render();
	void						loop();

	glm::vec3					camera_position{};
	glm::vec3					light_position{};

	const float					camera_step = 0.2f;

private :

	static void					callback(GLFWwindow* window, int key, int code, int action, int mode);

	mod1_core					core;
	mod1_program				program;
	mod1_loader					loader;
	std::vector<mod1_model *>	model_array;
	bool						render_request = true;
	glm::mat4					matrix_view{};
	glm::mat4					matrix_projection{};
	GLuint						uniform_transformation;
	GLuint						uniform_light;

	void						prepare_internal();
	void						render_internal();
};

