#version 400 core

struct							mod1_light_info
{
	float 						ambient_intensity;
	vec3						direct_direction;
	float						direct_intensity;
};

layout(location = 0) in	vec3	position;
layout(location = 1) in	vec3	normal;
layout(location = 2) in	vec3	color;

uniform mat4					object_transformation;
uniform mat4					camera_view;
uniform mat4					camera_projection;
uniform mod1_light_info			light_info;

flat out vec3					pass_color;

float							calculate_light_intensity()
{
	vec3						normal_global;
	vec3						to_light;
	float						n_dot_l;
	float						result;

	normal_global = normalize(normal);
	to_light = -light_info.direct_direction;
	n_dot_l = clamp(dot(normal_global, to_light), 0, 1);

	result = light_info.direct_intensity * n_dot_l;
	result += light_info.ambient_intensity;
	result = clamp(result, 0, 1);

	return (result);
}

#define FOG						0
#define BACKGROUND				vec3(0.8, 0.8, 0.8)

void							main()
{
	float						visibilty;

#if FOG
	visibilty = length(camera_view * object_transformation * vec4(position, 1)) / 10000;
	visibilty = clamp(visibilty, 0, 1);
#else
	visibilty = 0;
#endif

	pass_color = mix(color * calculate_light_intensity(), BACKGROUND, visibilty);

	gl_Position = camera_projection * camera_view * object_transformation * vec4(position, 1);
}
