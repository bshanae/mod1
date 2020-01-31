#version 330 core

in vec3					pass_color;

layout (location = 0) out vec4	result_color;

void					main()
{
	result_color = vec4(pass_color, 1);
}