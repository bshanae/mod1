#version 400

layout(triangles) in;
layout(line_strip, max_vertices = 6) out;

uniform mat4					object_transformation;
uniform mat4					camera_view;
uniform mat4					camera_projection;

in vec3							_normal[];
in vec3							_color[];

out vec3						color;

#define NORMAL_LENGTH			10
#define END_COLOR				vec3(1, 1, 1);

void							main()
{
	vec3						point;
	vec3						normal;

	for(int i = 0; i < gl_in.length(); i++)
	{
		point = gl_in[i].gl_Position.xyz;
		normal = _normal[i].xyz;

		gl_Position = camera_projection * camera_view * vec4(point, 1);
		color = _color[i];
		EmitVertex();

		gl_Position = camera_projection * camera_view * vec4(point + normal * NORMAL_LENGTH, 1);
		color = END_COLOR;
		EmitVertex();

		EndPrimitive();
	}
}