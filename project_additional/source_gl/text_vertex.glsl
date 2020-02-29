#version 330 core

layout (location = 0) in vec3	coordinate;
layout (location = 1) in vec2	UV;
out vec2						pass_UV;

uniform mat4					uniform_projection;

void							main()
{
	pass_UV = UV;
	gl_Position = uniform_projection * vec4(coordinate, 1);
}