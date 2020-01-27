#version 400 core

layout (location = 0) in vec2	UV;

out vec3						pass_color;

//uniform sampler2D	uniform_texture;

void							main()
{
//	pass_color = texture(uniform_texture, UV).xyz;
	gl_Position = vec4(UV.x, UV.y, 0.0, 1.0);
	pass_color = vec3(UV.x, UV.y, 0);
}