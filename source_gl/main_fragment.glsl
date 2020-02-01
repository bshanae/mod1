#version 330 core

flat in vec3		pass_color;

//out vec4			result_color;

layout(location = 0) out vec4 result_color;

void				main()
{
//	result_color = pass_color;
	result_color = vec4(pass_color, 1);
}