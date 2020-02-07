#version 330 core

flat in vec4		pass_color;
out vec4			result_color;

void				main()
{
	result_color = pass_color;
}