#version 400 core

in vec3             pass_color;
in float			pass_light_intensity;

out vec4			result_color;

void main()
{
	result_color = vec4(pass_color * pass_light_intensity, 1.0f);
}