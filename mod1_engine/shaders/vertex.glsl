#version 400 core

layout(location = 0) in	vec3	position;
layout(location = 1) in	vec3	normal;
layout(location = 2) in	vec3	color;

uniform mat4					transformation;
uniform vec3					light_position;

out vec3						pass_color;
out float						pass_light_intensity;

void main()
{
    vec4						position_global = transformation * vec4(position, 1.0);

	vec3						normal_global = (transpose(inverse(transformation)) * vec4(normal, 1.0)).xyz;
	vec3						to_light = light_position - position_global.xyz;

	normal_global = normalize(normal_global);
	to_light = normalize(to_light);

	float						n_dot_l = dot(normal_global, to_light);

    pass_light_intensity = min(max(n_dot_l, 0.001f), 1.f) + 0.1;
    pass_color = color;

    gl_Position = position_global;
}
