#version 400 core

in vec3 position;
in vec3 normal;

uniform mat4 transformation;
uniform vec3 light_position;

void main()
{
    gl_Position = transformation * vec4(position, 1.0);
}
