#pragma once

#include "mod1_preference.h"

#define MOD1_PLANE_COLOR_DATA			std::vector<mod1_point3<float>>

#define MOD1_TERRAIN_RAW_DATA			std::vector<mod1_point3<int>>
#define MOD1_TERRAIN_RAW_DATA_RI		MOD1_TERRAIN_RAW_DATA::reverse_iterator
#define MOD1_TERRAIN_DEFAULT_DELTA		10
#define MOD1_TERRAIN_DEFAULT_SIZE		mod1_point3<int>(100)
#define MOD1_TERRAIN_INDENT				0.3
#define MOD1_TERRAIN_MIN_SIZE			10

#define MOD1_TERRAIN_INFO_RAW			0x000001u
#define MOD1_TERRAIN_INFO_MODEL			0x000010u
#define MOD1_TERRAIN_INFO_POINT			0x000100u
#define MOD1_TERRAIN_INFO_NORMAL		0x001000u
#define MOD1_TERRAIN_INFO_COLOR			0x010000u
#define MOD1_TERRAIN_INFO_POLYGON		0x100000u

#define MOD1_WATER_EPSILON				0.01f