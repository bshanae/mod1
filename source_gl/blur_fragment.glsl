#version 330 core

in vec2					UV;

out vec4				result_color;

uniform sampler2D		uniform_texture;

void					main()
{
//	result_color = texture(uniform_texture, UV).rgb;
	result_color = vec4(texture(uniform_texture, UV).rgb, 1);
}