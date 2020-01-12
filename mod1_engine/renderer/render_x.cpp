#include "renderer.h"

using namespace		mod1_engine;

void 				renderer::render()
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
		model->draw();
	}

	program.stop();
	core.swap_buffers();
}