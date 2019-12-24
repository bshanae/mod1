#pragma once

#include "mod1_OpenGL.h"
#include "mod1_error.h"
#include "mod1_core.h"
#include "mod1_program.h"
#include "mod1_model.h"
#include "mod1_loader.h"
#include "mod1_camera.h"

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

	const glm::vec3				camera_position = glm::vec3(5, 5, 20);

private :

	static void					callback(GLFWwindow* window, int key, int code, int action, int mode);

	std::vector<mod1_model *>	model_array;
	bool						render_request = true;

	mod1_core					core;
	mod1_program				program;
	mod1_loader					loader;
	mod1_camera					camera;

	glm::vec3					light_position;

	GLuint						uniform_transformation;
	GLuint						uniform_light;

	void						prepare_internal();
	void						render_internal();

};

