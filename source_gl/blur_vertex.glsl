#version 400 core

in vec2				UV;

out vec3			pass_color;

uniform sampler2D	uniform_texture;

void				main()
{
	pass_color = texture(uniform_texture, UV).xyz;
}