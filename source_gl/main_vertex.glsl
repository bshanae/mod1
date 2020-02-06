#version 330 core

layout (location = 0) in vec3	position;
layout (location = 1) in vec3	normal;
layout (location = 2) in vec3	color;
flat out vec3					pass_color;

uniform struct
{
	float 						ambient_intensity;
	vec3						direct_direction;
	float						direct_intensity;
}								light;

uniform struct
{
	vec3						position;
	mat4						view;
	mat4						projection;
}								camera;

uniform struct
{
	mat4						transformation;
	float						specular;
}								object;

vec3							compute_color(vec4 global_position)
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
	to_light = -light.direct_direction;
	to_camera = normalize(camera.position - global_position.xyz);

	n_dot_l = clamp(dot(normal_global, to_light), 0, 1);
	diffusion = light.direct_intensity * n_dot_l;

	reflection = reflect(-to_light, normal_global);
	specular = pow(max(dot(to_camera, reflection), 0.0), 10);

	result = color * light.ambient_intensity;
	result += color * diffusion;
	result += object.specular * vec3(1, 1, 1) * specular;

	result = clamp(result, 0, 1);

	return (result);
}

void							main()
{
	vec4						global_position = object.transformation * vec4(position, 1);

	pass_color = compute_color(global_position);
	gl_Position = camera.projection * camera.view * global_position;
}
