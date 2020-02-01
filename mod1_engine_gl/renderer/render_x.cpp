#include "renderer.h"

using namespace			mod1_engine_gl;

void 					renderer::render_internal()
{
	core.clear(MOD1_BACKGROUND);

	main_program.start();

	main_program.camera_view.upload(camera.view());

	main_program.light_ambient_intensity.upload(light_info.ambient_intensity);
	main_program.light_direct_direction.upload(light_info.direct_direction);
	main_program.light_direct_intensity.upload(light_info.direct_intensity);

	for (auto &model : model_array)
	{
		main_program.object_transformation.upload(model->transformation());
		model->draw(core);
	}
	main_program.stop();
	core.swap_buffers();
	render_request = false;
}

void 					renderer::render_no_swap()
{
	core.clear(point3<float>(0.4));

	main_program.start();

	main_program.camera_projection.upload(camera.projection());
	main_program.camera_view.upload(camera.view());

	main_program.light_ambient_intensity.upload(light_info.ambient_intensity);
	main_program.light_direct_direction.upload(light_info.direct_direction);
	main_program.light_direct_intensity.upload(light_info.direct_intensity);

	for (auto &model : model_array)
	{
		main_program.object_transformation.upload(model->transformation());
		model->draw(core);
	}
	main_program.stop();
}

void					renderer::render()
{
	render_request = true;
}