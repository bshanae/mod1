#pragma once

#include "mod1_main/mod1_macros.h"
#include "mod1_main/mod1_control.h"

#include "mod1_libraries/FastNoise/FastNoise.h"

#include "mod1_algorithm/namespace.h"

#include "mod1_algorithm/plane/plane.h"

#include <fstream>
#include <vector>
#include <iostream>

class							mod1_algorithm::terrain : private plane
{
public :

	friend class				water;

								terrain() = default;
								~terrain() = default;

	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_source, "Mod1 Terrain : Invalid source file")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_pattern, "Mod1 Terrain : Invalid pattern")
	MOD1_GENERATE_EXCEPTION_DECLARATION(exception_point_number, "Mod1 Terrain : Map can't have more, than 50 points")

	void						parse(const std::string &file);
	void						build() final;

	mod1_engine_gl::model		*model() override;
	const mod1_engine_gl::model	*model() const override;

	static float				interpolate_linear(float min, float max, float ratio);
	static float				interpolate_cosine(float min, float max, float ratio);
	static float				interpolate_smooth(float min, float max, float ratio);

	using						plane::add_color;

private :

	MOD1_TERRAIN_RAW_DATA		data_raw;
	point3<double>				min_raw = point3<double>(std::numeric_limits<double>::max());
	point3<double>				max_raw = point3<double>(std::numeric_limits<double>::min());
	point3<double>				diff_raw;

	static double				parse_coordinate(std::ifstream &stream, bool eat_delimiter);
	void						normalize();
	void						resize();

	void						generate_hill_helper(const point2<int> &iter, const float &height);
	void						generate_hill_fix(const point2<int> &iter, const int &step);
	void						generate_hill(const point3<double> &summit);

	FastNoise					noise_generator;

	float						generate_noise(
								const point2<int> &iter,
								const float &frequency,
								const float &range,
								const point2<float> &offset = point2<float>(),
								const float &power = 1) const;
	void						apply_noise(
								const point2<int> &iter,
								const float &frequency,
								const float &range,
								const point2<float> &offset = point2<float>(),
								const float &power = 1);
	void						apply_noise(
								const float &frequency,
								const float &range,
								const point2<float> &offset = point2<float>(),
								const float &power = 1);

	point2<int>					find_iter(const point3<double> &object) const;

	using						plane::size;
	using						plane::real_size;
	using						plane::min;
	using						plane::max;
	using						plane::delta;
	using						plane::final_min;
	using						plane::final_max;
};
