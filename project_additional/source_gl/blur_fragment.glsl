#version 330 core

in vec2					pass_UV;
out vec4				result_color;

uniform sampler2D		uniform_texture;

bool					is_valid_helper(float x)
{
	if (x < 0 || x > 1)
		return (false);
	return (true);
}

bool					is_valid(vec2 pass_UV)
{
	return (is_valid_helper(pass_UV.x) && is_valid_helper(pass_UV.y));
}

vec3					blur()
{

	float				dx;
	float				dy;

	vec3				sum;
	int					count = 0;

	float				screen_width = 1024;
	float				screen_height = 720;

	dx = 1 / screen_width;
	dy = 1 / screen_height;
	sum = vec3(0, 0, 0);

	for (int i = -10; i < 10; i++)
		for (int j = -10; j < 10; j++)
		{
			if (!is_valid(pass_UV + vec2(i * dx, j  * dy)))
				continue ;
			sum += texture(uniform_texture, pass_UV + vec2(i * dx, j  * dy)).xyz;
			count++;
		}
	return (sum / count);
}

void					main()
{
	result_color = vec4(blur(), 1);
}