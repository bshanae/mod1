#pragma once

//												GENERAL

#define TYPE(x)									decltype(x)

#define CONCAT_(a, b)							a##b
#define CONCAT(a, b)							CONCAT_(a, b)

#define STRING(x)								#x

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
#define MOD1_PLANE_REAL_SIZE(size)				point2<int>(MOD1_PLANE_REAL_SIZE_X(size.x), size.y)

#define MOD1_PLANE_REAL_INDEX_X(iter_x)			((iter_x) * 2 - (iter_x != 0))

#define MOD1_PLANE_NUMBER_OF_POINTS(size)		(MOD1_PLANE_REAL_SIZE_X(size.x) * size.y)
#define MOD1_PLANE_NUMBER_OF_SQUARES(size)		(((size.x) - 1) * ((size.y) - 1))
#define MOD1_PLANE_NUMBER_OF_TRIANGLES(size)	(MOD1_PLANE_NUMBER_OF_SQUARES(size) * 2)

#define MOD1_PLANE_COLOR_DATA					std::vector<point3<float>>

//												TERRAIN

#define MOD1_TERRAIN_RAW_DATA					std::vector<point3<int>>
#define MOD1_TERRAIN_RAW_DATA_RI				MOD1_TERRAIN_RAW_DATA::reverse_iterator
#define MOD1_TERRAIN_DEFAULT_DELTA				10
#define MOD1_TERRAIN_DEFAULT_SIZE				point3<int>(100)
#define MOD1_TERRAIN_INDENT						0.3
#define MOD1_TERRAIN_MIN_SIZE					10

//												WATER

#define MOD1_WATER_EPSILON						0.01f

#define MOD1_WATER_RIGHT						point2<int>(1, 0)
#define MOD1_WATER_UPPER						point2<int>(0, -1)
#define MOD1_WATER_LEFT							point2<int>(-1, 0)
#define MOD1_WATER_DOWN							point2<int>(0, 1)

#define DEBUG	{ int CONCAT(x_, __LINE__) = glGetError(); if (CONCAT(x_, __LINE__)) exit(1); }
