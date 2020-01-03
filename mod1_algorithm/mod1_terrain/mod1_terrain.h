#pragma once

#include "mod1_plane.h"

#include <fstream>
#include <vector>

#define MOD1_MAP_RAW_DATA		std::vector<mod1_point3<int>>
#define MOD1_MAP_RAW_DATA_RI	MOD1_MAP_RAW_DATA::reverse_iterator
#define MOD1_MAP_COLOR_DATA		std::vector<mod1_point3<float>>
#define MOD1_MAP_DEFAULT_DELTA	10
#define MOD1_MAP_DEFAULT_SIZE	mod1_point3<int>(100)
#define MOD1_MAP_INDENT			0.3
#define MOD1_MAP_MIN_SIZE		10

#define MOD1_MAP_INFO_RAW		0x000001u
#define MOD1_MAP_INFO_MODEL		0x000010u
#define MOD1_MAP_INFO_POINT		0x000100u
#define MOD1_MAP_INFO_NORMAL	0x001000u
#define MOD1_MAP_INFO_COLOR		0x010000u
#define MOD1_MAP_INFO_POLYGON	0x100000u

class							mod1_terrain : private mod1_plane
{
public :
								mod1_terrain() = default;
								~mod1_terrain() = default;

	struct						exception_source : public std::exception
	{
		const char				*what() const noexcept override;
	};

	struct						exception_pattern : public std::exception
	{
		const char				*what() const noexcept override;
	};

	struct						exception_search : public std::exception
	{
		const char				*what() const noexcept override;
	};

	struct						exception_color : public std::exception
	{
		const char				*what() const noexcept override;
	};

	void						parse(const std::string &file);
	void						build() final;

	mod1_model					*model() final;

	void						info(unsigned int flags = MOD1_MAP_INFO_RAW | MOD1_MAP_INFO_MODEL) const;

	void						push_color(const mod1_point3<float> &color);

	static float				interpolate_linear(float min, float max, float ratio);
	static float				interpolate_cosine(float min, float max, float ratio);
	static float				interpolate_smooth(float min, float max, float ratio);

private :

	MOD1_MAP_RAW_DATA			data_raw;
	mod1_point3<int>			min_raw = mod1_point3<int>(INT_MAX, INT_MAX, INT_MAX);
	mod1_point3<int>			max_raw = mod1_point3<int>(-INT_MAX, -INT_MAX, -INT_MAX);
	mod1_point3<int>			diff_raw;
	bool						case_one_point = false;

	static float				parse_coordinate(std::ifstream &stream, bool eat_delimiter);

	MOD1_MAP_COLOR_DATA			data_color;

	mod1_point3<float>			compute_color(const float &height) const;

	mod1_point2<int>			min_i;
	mod1_point2<int>			max_i;
	int							delta_i = 0;

	void						prepare();

	void						update_delta(const int &i, const int &j, const int &index);
	void 						compute_delta();
	void						optimize_delta();

	bool						write_height(const mod1_point2<int> &iter, const float &height);
	void						generate_hill(const mod1_point3<int> &summit);

	mod1_point2<int>			find_ptr(const mod1_point3<int> &object) const;

	friend class				mod1_water;
};
