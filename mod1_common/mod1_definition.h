#pragma once

//												GENERAL

#define TYPE(x)									decltype(x)

#define MOD1_DISABLE							0
#define MOD1_ENABLE								1

#define MOD1_ENABLED(x)							x == MOD1_ENABLE
#define MOD1_DISABLED(x)						x == MOD1_DISABLE

#define MOD1_MIN(a, b)							((a) < (b) ? (a) : (b))
#define MOD1_MAX(a, b)							((a) > (b) ? (a) : (b))

#define MOD1_EPSILON							0.01f

#define MOD1_INTERNAL(name)						name##_internal
#define MOD1_INTERNAL_RETURN(name)				const TYPE(MOD1_INTERNAL(name)) &

//												MODEL

#define MOD1_MODEL_POINT_GROUP					3
#define MOD1_MODEL_INDEX_GROUP					3
#define MOD1_MODEL_NORMAL_GROUP					3
#define MOD1_MODEL_COLOR_GROUP					4
#define MOD1_MODEL_TEXTURE_GROUP				2


//												PLANE

#define MOD1_PLANE_REAL_SIZE_X(size_x)			((size_x) * 2 - 2)
#define MOD1_PLANE_REAL_SIZE(size)				point2<int>(MOD1_PLANE_REAL_SIZE_X(size.x), size.y)

#define MOD1_PLANE_REAL_INDEX_X(iter_x)			((iter_x) * 2 - (iter_x != 0))

#define MOD1_PLANE_NUMBER_OF_POINTS(size)		(MOD1_PLANE_REAL_SIZE_X(size.x) * size.y)
#define MOD1_PLANE_NUMBER_OF_SQUARES(size)		(((size.x) - 1) * ((size.y) - 1))
#define MOD1_PLANE_NUMBER_OF_TRIANGLES(size)	(MOD1_PLANE_NUMBER_OF_SQUARES(size) * 2)

#define MOD1_PLANE_COLOR_DATA					std::vector<point3<float>>

//												TERRAIN

#define MOD1_TERRAIN_RAW_DATA					std::vector<point3<double>>
#define MOD1_TERRAIN_RAW_DATA_RI				MOD1_TERRAIN_RAW_DATA::reverse_iterator