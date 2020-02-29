#pragma once

#include "algorithm/namespace.h"

#include "algorithm/plane/plane.h"

enum class						mod1_algorithm::terrain_color_type
{
	positive,
	negative
};

class							general;

class							mod1_algorithm::terrain : private plane<terrain_color_type>
{
	friend class				water;
	friend class				::general;

public :

MOD1_GENERATE_EXCEPTION_DECLARATION(exception_source, "Mod1 Terrain : Invalid source file")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_extension, "Mod1 Terrain : Source file has invalid extension")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_pattern, "Mod1 Terrain : Invalid pattern")
MOD1_GENERATE_EXCEPTION_DECLARATION(exception_point_number, "Mod1 Terrain : Map can't have more, than 50 points")

								terrain() = default;
								~terrain() final = default;

	void						parse_map(const std::string &file);
	void						parse_noise(const std::string &file);
	void						build() final;

	mod1_engine_gl::model		*model() override;
	const mod1_engine_gl::model	*model() const override;

	static float				interpolate_linear(float min, float max, float ratio);
	static float				interpolate_cosine(float min, float max, float ratio);
	static float				interpolate_smooth(float min, float max, float ratio);

	void						add_color(const point3<float> &color, const terrain_color_type &type) final;
	void 						add_color(const point3<int> &color, const terrain_color_type &type) final;

private :

//								GENERAL

	MOD1_TERRAIN_RAW_DATA		data_raw;
	point3<double>				min_raw = point3<double>(std::numeric_limits<double>::max());
	point3<double>				max_raw = point3<double>(std::numeric_limits<double>::min());

	point3<double>				min_prepared;
	point3<double>				max_prepared;
	point3<double>				diff_prepared;

	static double				parse_map_coordinate(std::ifstream &stream, bool eat_delimiter);

	void						prepare();
	void						normalize();
	void						resize();

	static void					check_extension(const std::string &path, const std::string &extension);

//								HILL

	void						generate_hill_helper(const point2<int> &iter, const float &new_height);
	void						generate_hill_fix(const point2<int> &iter, const int &step);
	void						generate_hill(const point3<double> &summit);

//								NOISE

	typedef struct
	{
		float					frequency;
		float					range;
		point2<float>			offset;
		float					power;
	}							noise_config;

	std::vector<noise_config>	noise_hill;
	std::vector<noise_config>	noise_general;

	static void					parse_noise_line(std::vector<noise_config> &target, std::stringstream &stream);

	FastNoise					noise_generator;

	float						generate_noise(
								const point2<int> &iter,
								const float &frequency,
								const float &range,
								const point2<float> &offset = point2<float>(),
								const float &power = 1) const;
	float						generate_noise(
								const point2<int> &iter,
								const noise_config &config);

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

	void						apply_noise(
								const point2<int> &iter,
								const noise_config &config);
	void						apply_noise(
								const noise_config &config);

	point2<int>					find_iter(const point3<double> &object) const;

//								COLOR

	std::vector<point3<float>>	color_data_positive;
	std::vector<point3<float>>	color_data_negative;

	point4<float>				compute_color(const float &height) const;
	void 						update_color(const bool &save = false) final;

//								PARENT

	using						plane::size;
	using						plane::real_size;
	using						plane::min;
	using						plane::max;
	using						plane::delta;
	using						plane::final_min;
	using						plane::final_max;
};
