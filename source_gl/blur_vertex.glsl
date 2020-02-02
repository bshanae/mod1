#version 330 core

layout (location = 0) in vec3	coordinate;
out vec2						UV;

uniform sampler2D				uniform_texture;

void							main()
{
	UV = (coordinate.xy + vec2(1, 1)) / 2;
	gl_Position = vec4(coordinate, 1);
}