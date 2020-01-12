#version 400 core

layout(location = 0) in	vec2	texture_coordinate;

out vec2						pass_coordinate;

void main()
{
	texCoord = texture_coordinate;
	gl_Position = vec4(texture_coordinate.x, texture_coordinate.y, 0.0, 1.0);
}