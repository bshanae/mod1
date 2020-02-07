#version 330 core

layout (location = 0) in vec3	position;
layout (location = 1) in vec3	normal;
layout (location = 2) in vec4	color;
flat out vec4					pass_color;

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
	float						ambient_receptivity;
	float						diffuse_receptivity;
	float						specular_receptivity;
}								object;

vec4							compute_color(vec4 global_position)
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

	result = object.ambient_receptivity * color.rgb * light.ambient_intensity;
	result += object.diffuse_receptivity * color.rgb * diffusion;
	result += object.specular_receptivity * vec3(1, 1, 1) * specular;

	result = clamp(result, 0, 1);

	return (vec4(result.rgb, color.a));
}

void							main()
{
	vec4						global_position = object.transformation * vec4(position, 1);

	pass_color = compute_color(global_position);
	gl_Position = camera.projection * camera.view * global_position;
}
