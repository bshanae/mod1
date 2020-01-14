#include "renderer.h"

using namespace			mod1_engine;

void 					renderer::render_internal()
{
	program.start();

	glClearColor(MOD1_BACKGROUND.x, MOD1_BACKGROUND.y, MOD1_BACKGROUND.z, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	program.camera_view.upload(camera.view());

	program.light_ambient_intensity.upload(light_info.ambient_intensity);
	program.light_point_position.upload(light_info.point_position);
	program.light_point_intensity.upload(light_info.point_intensity);
	program.light_point_power.upload(light_info.point_power);


	light_cube.transformation() = glm::translate(glm::mat4(1), light_info.point_position);

	static GLuint		x = -1;

	if (x == -1)
		x = glGetUniformLocation(program.object(), "x");

	int i = 0;

	for (auto &model : model_array)
	{
		if (i++ == 2)
			glUniform1i(x, 1);
		else
			glUniform1i(x, 0);

		program.object_transformation.upload(model->transformation());
		model->use();
		glDrawElements(GL_TRIANGLES, model->vertex_number(), GL_UNSIGNED_INT, nullptr);
	}
	program.stop();
	core.swap_buffers();
	render_request = false;
}

void					renderer::render()
{
	render_request = true;
}