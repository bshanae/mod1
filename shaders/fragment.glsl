#version 400 core

flat in vec3		pass_color;
flat in float		pass_light_intensity;

out vec4			result_color;

void				main()
{
	result_color = vec4(pass_color * pass_light_intensity, 1);
}