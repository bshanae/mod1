#version 400

layout(triangles) in;
layout(line_strip, max_vertices = 6) out;

uniform mat4					object_transformation;
uniform mat4					camera_view;
uniform mat4					camera_projection;

in vec4							_normal[];
out vec3						color;

void main()
{
	int i;
	for(i = 0; i < gl_in.length(); i++)
	{
		vec3 P = gl_in[i].gl_Position.xyz;
		vec3 N = _normal[i].xyz;

		gl_Position = camera_projection * camera_view * vec4(P, 1.0);
		color = vec3(0, 0, 0);
		EmitVertex();

		gl_Position = camera_projection * camera_view * vec4(P + N * 50., 1.0);
		color = vec3(0, 0, 1);
		EmitVertex();

		EndPrimitive();
	}
}