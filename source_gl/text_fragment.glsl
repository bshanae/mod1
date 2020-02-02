#version 330 core

in vec2				texture_coordinates;
out vec4			result_color;

uniform sampler2D	uniform_texture;
uniform vec3		uniform_color;

void main()
{
	vec4			sampled;

	sampled = vec4(1, 1, 1, texture(uniform_texture, texture_coordinates).r);
//	result_color = vec4(uniform_color, 1) * sampled;
	result_color = vec4(1, 0, 0, 1);
}