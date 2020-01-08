#version 400 core

struct							mod1_light_info
{
	float 						ambient_intensity;
	vec3						point_position;
	float						point_intensity;
	float						point_power;
};

layout(location = 0) in	vec3	position;
layout(location = 1) in	vec3	normal;
layout(location = 2) in	vec3	color;

uniform mat4					object_transformation;
uniform mat4					camera_view;
uniform mat4					camera_projection;
uniform mod1_light_info			light_info;

out vec4						_normal;

float							calculate_light_intensity()
{
	vec3						normal_global;
	vec3						to_light;
	float						n_dot_l;
	float						result;

	normal_global = normalize(normal);
	to_light = normalize(light_info.point_position - position);
	n_dot_l = clamp(dot(normal_global, to_light), 0, 1);

	result = pow(light_info.point_intensity * n_dot_l, light_info.point_power);
	result += light_info.ambient_intensity;
	result = clamp(result, 0, 1);

	return (result);
}

void							main()
{
	_normal = vec4(normal, 1);

	gl_Position = object_transformation * vec4(position, 1);
}
