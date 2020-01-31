#version 330 core

layout (location = 0) in vec3	UV;

out vec3						pass_color;

uniform sampler2D				uniform_texture;

void							main()
{
	pass_color = texture(uniform_texture, UV.xy).xyz;
	gl_Position = vec4(UV.x, UV.y, 1.0, 1.0);
}