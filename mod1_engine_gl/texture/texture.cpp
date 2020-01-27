#include "texture.h"

using namespace		mod1_engine_gl;

					texture::texture()
{
	glGenTextures(1, &object_internal);
}

					texture::texture(const int &width, const int &height)
{
	glGenTextures(1, &object_internal);
	build(width, height);
}

					texture::~texture()
{
	glDeleteTextures(1, &object_internal);
}

void				texture::build(const int &width, const int &height)
{
	start();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
		0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stop();

	resolution = point2<int>(width, height);
}

void				texture::start() const
{
	glBindTexture(GL_TEXTURE_2D, object_internal);
}

void				texture::stop() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint				texture::object() const
{
	return (object_internal);
}

void				texture::save(const char *file) const
{
	FILE			*output_image;

	int             i;
	int				j;
	int 			k;

	auto			*pixels = (unsigned char*)malloc(resolution.x * resolution.y * 3);

	glReadBuffer(GL_COLOR_ATTACHMENT0);
	glReadPixels(0, 0, resolution.x, resolution.y, GL_RGB, GL_UNSIGNED_BYTE, pixels);

	output_image = fopen(file, "wt");
	fprintf(output_image,"P3\n");
	fprintf(output_image,"%d %d\n", resolution.x, resolution.y);
	fprintf(output_image,"255\n");

	k = 0;
	for(i = 0; i < resolution.x; i++)
	{
		for(j = 0; j < resolution.y; j++)
		{
			fprintf(output_image,"%u %u %u ",
				(unsigned int)pixels[k + 0],
				(unsigned int)pixels[k + 1],
				(unsigned int)pixels[k + 2]);
//			std::cerr
//				<< "("
//				<< (unsigned int)pixels[k + 0] << ","
//				<< (unsigned int)pixels[k + 1] << ","
//				<< (unsigned int)pixels[k + 2]
//				<< ") ";
			k += 3;
		}
		std::cerr << std::endl;
		fprintf(output_image,"\n");
	}
	free(pixels);
}