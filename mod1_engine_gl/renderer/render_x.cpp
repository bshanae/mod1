#include "renderer.h"

using namespace			mod1_engine_gl;

void 					renderer::render_internal()
{
	core.clear(MOD1_BACKGROUND);

	program.start();

	program.camera_view.upload(camera.view());

	program.light_ambient_intensity.upload(light_info.ambient_intensity);
	program.light_point_position.upload(light_info.point_position);
	program.light_point_intensity.upload(light_info.point_intensity);
	program.light_point_power.upload(light_info.point_power);

	light_cube.transformation() = glm::translate(glm::mat4(1), light_info.point_position);

	for (auto &model : model_array)
	{
		program.object_transformation.upload(model->transformation());
		model->start();
		core.draw(model->vertex_number());
		model->stop();
	}
	program.stop();
	core.swap_buffers();
	render_request = false;
}

void					renderer::render()
{
	render_request = true;
}