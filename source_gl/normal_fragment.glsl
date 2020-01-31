#version 330 core

in vec3				color;

out vec4			result_color;

void				main()
{
	result_color = vec4(color, 1);
}