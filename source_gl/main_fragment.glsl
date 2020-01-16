#version 400 core

flat in vec3		pass_color;

out vec4			result_color;

void				main()
{
	result_color = vec4(pass_color, 1);
}