#version 330 core

layout (location = 0) in vec3	coordinate;
layout (location = 1) in vec2	UV;
out vec2						pass_UV;

uniform sampler2D				uniform_texture;

void							main()
{
	pass_UV = UV;
	gl_Position = vec4(coordinate, 1);
}