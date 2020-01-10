#pragma once

//												GENERAL

#define MOD1_DISABLE							0
#define MOD1_ENABLE								1

#define MOD1_ENABLED(x)							x == MOD1_ENABLE
#define MOD1_DISABLED(x)						x == MOD1_DISABLE

#define MOD1_MIN(a, b)							((a) < (b) ? (a) : (b))
#define MOD1_MAX(a, b)							((a) > (b) ? (a) : (b))

//												PLANE

#define MOD1_PLANE_POINT_SIZE					3
#define MOD1_PLANE_INDEX_SIZE					3
#define MOD1_PLANE_NORMAL_SIZE					3
#define MOD1_PLANE_COLOR_SIZE					3

#define MOD1_PLANE_REAL_SIZE_X(size_x)			((size_x) * 2 - 2)
#define MOD1_PLANE_REAL_INDEX_X(iter_x)			((iter_x) * 2 - (iter_x != 0))

#define MOD1_PLANE_NUMBER_OF_POINTS(size)		(MOD1_PLANE_REAL_SIZE_X(size.x) * size.y)
#define MOD1_PLANE_NUMBER_OF_SQUARES(size)		(((size.x) - 1) * ((size.y) - 1))
#define MOD1_PLANE_NUMBER_OF_TRIANGLES(size)	(MOD1_PLANE_NUMBER_OF_SQUARES(size) * 2)

#define MOD1_PLANE_COLOR_DATA					std::vector<mod1_point3<float>>

//												TERRAIN

#define MOD1_TERRAIN_RAW_DATA					std::vector<mod1_point3<int>>
#define MOD1_TERRAIN_RAW_DATA_RI				MOD1_TERRAIN_RAW_DATA::reverse_iterator
#define MOD1_TERRAIN_DEFAULT_DELTA				10
#define MOD1_TERRAIN_DEFAULT_SIZE				mod1_point3<int>(100)
#define MOD1_TERRAIN_INDENT						0.3
#define MOD1_TERRAIN_MIN_SIZE					10

#define MOD1_TERRAIN_INFO_RAW					0x000001u
#define MOD1_TERRAIN_INFO_MODEL					0x000010u
#define MOD1_TERRAIN_INFO_POINT					0x000100u
#define MOD1_TERRAIN_INFO_NORMAL				0x001000u
#define MOD1_TERRAIN_INFO_COLOR					0x010000u
#define MOD1_TERRAIN_INFO_POLYGON				0x100000u

//												WATER

#define MOD1_WATER_EPSILON						0.01f