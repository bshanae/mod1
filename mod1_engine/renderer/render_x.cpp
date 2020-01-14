#include "renderer.h"

using namespace		mod1_engine;

void 				renderer::render_internal()
{
	program.start();

	glClearColor(MOD1_BACKGROUND.x, MOD1_BACKGROUND.y, MOD1_BACKGROUND.z, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUniformMatrix4fv(uniform_camera_view, 1, GL_FALSE, glm::value_ptr(camera.view()));

	glUniform1f(uniform_light_ambient_intensity, light_info.ambient_intensity);
	glUniform3f(uniform_light_point_position,
		light_info.point_position.x,
		light_info.point_position.y,
		light_info.point_position.z);
	glUniform1f(uniform_light_point_intensity, light_info.point_intensity);
	glUniform1f(uniform_light_point_power, light_info.point_power);

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

		glUniformMatrix4fv(uniform_object_transformation, 1, GL_FALSE, glm::value_ptr(model->transformation()));
		model->use();
		glDrawElements(GL_TRIANGLES, model->vertex_number(), GL_UNSIGNED_INT, nullptr);
	}
	program.stop();
	core.swap_buffers();
	render_request = false;
}

void				renderer::render()
{
	render_request = true;
}