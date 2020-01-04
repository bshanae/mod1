#version 400 core

layout(location = 0) in	vec3	position;
layout(location = 1) in	vec3	normal;
layout(location = 2) in	vec3	color;

uniform mat4					view;
uniform mat4					projection;
uniform vec3					light_position;

out vec3						pass_color;
out float						pass_light_intensity;

void							main()
{
	vec3						normal_global = normalize(normal);
	vec3						to_light = normalize(light_position - position);

	float						n_dot_l = dot(normal_global, to_light);

    pass_light_intensity = 0.8 * clamp(n_dot_l, 0, 1) + 0.3;
    pass_color = color;

    gl_Position = projection * view * vec4(position, 1);
}
