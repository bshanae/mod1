#version 330 core

struct							mod1_light_info
{
	float 						ambient_intensity;
	vec3						direct_direction;
	float						direct_intensity;
};

layout (location = 0) in vec3	position;
layout (location = 1) in vec3	normal;
layout (location = 2) in vec3	color;
flat out vec3					pass_color;

uniform mat4					object_transformation;

uniform vec3					camera_position;
uniform mat4					camera_view;
uniform mat4					camera_projection;
uniform mod1_light_info			light_info;

vec3							light(vec4 global_position)
{
	vec3						normal_global;
	vec3						to_light;
	vec3						to_camera;

	float						n_dot_l;
	float						diffusion;

	vec3						reflection;
	float						specular;

	vec3						result;

	normal_global = normalize(normal);
	to_light = -light_info.direct_direction;
	to_camera = normalize(camera_position - global_position.xyz);

	n_dot_l = clamp(dot(normal_global, to_light), 0, 1);
	diffusion = light_info.direct_intensity * n_dot_l;

	reflection = reflect(-to_light, normal_global);
	specular = pow(max(dot(to_camera, reflection), 0.0), 2);

	result = color * light_info.ambient_intensity;
	result += color * diffusion;
	result += 0.1 * vec3(1, 1, 1) * specular;

	result = clamp(result, 0, 1);

	return (result);
}

void							main()
{
	vec4						global_position = object_transformation * vec4(position, 1);

	pass_color = light(global_position);
	gl_Position = camera_projection * camera_view * global_position;
}
