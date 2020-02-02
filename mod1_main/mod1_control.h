#pragma once

#include "mod1_macros.h"

//											GLOBAL

#define MOD1_WINDOW_WIDTH					720
#define MOD1_WINDOW_HEIGHT					480

#define MOD1_NORMAL_TEST					MOD1_DISABLE

#if MOD1_ENABLED(MOD1_NORMAL_TEST)
#define MOD1_SOURCE_SHADER_VERTEX			"./shaders/test_vertex.glsl"
#define MOD1_SOURCE_SHADER_GEOMETRY			"./shaders/test_geometry.glsl"
#define MOD1_SOURCE_SHADER_FRAGMENT			"./shaders/test_fragment.glsl"
#else
#define MOD1_SOURCE_SHADER_VERTEX			"./source_gl/main_vertex.glsl"
#define MOD1_SOURCE_SHADER_FRAGMENT			"./source_gl/main_fragment.glsl"
#endif

//											ENGINE

#define MOD1_DEPTH_TEST						MOD1_ENABLE
#define MOD1_SHOW_BACK_OF_POLYGON			MOD1_ENABLE
#define MOD1_SRGB							MOD1_DISABLE

#define MOD1_LIGHT_AMBIENT_INTENSITY		0.2
#define MOD1_LIGHT_DIRECT_DIRECTION			0, -1, 0
#define MOD1_LIGHT_DIRECT_INTENSITY			0.8

#define MOD1_CAMERA_POSITION				500, 300, 1200
#define MOD1_CAMERA_MOVEMENT_SPEED			20
#define MOD1_CAMERA_ROTATION_SPEED			0.04

#define MOD1_BACKGROUND						point3<float>(0.8f)

//											MAIN

#define MOD1_USE_TERRAIN					MOD1_ENABLE
#define MOD1_USE_WATER						MOD1_ENABLE

//											TERRAIN

#define MOD1_TERRAIN_SIZE					point2<double>(1000, 1000)
#define MOD1_TERRAIN_DELTA					10
#define MOD1_TERRAIN_INDENT					0.3

#define MOD1_TERRAIN_HILLS					MOD1_ENABLE
#define MOD1_TERRAIN_NOISE					MOD1_DISABLE

#define MOD1_TERRAIN_NOISE_HILL				MOD1_DISABLE
#define MOD1_TERRAIN_NOISE_HILL_FREQUENCY	10
#define MOD1_TERRAIN_NOISE_HILL_RANGE		10
#define MOD1_TERRAIN_NOISE_HILL_OFFSET		point2<float>(0)
#define MOD1_TERRAIN_NOISE_HILL_ADD			0.8

#define MOD1_TERRAIN_NOISE_A				MOD1_DISABLE
#define MOD1_TERRAIN_NOISE_A_FREQUENCY		2
#define MOD1_TERRAIN_NOISE_A_RANGE			5000
#define MOD1_TERRAIN_NOISE_A_OFFSET			point2<float>(50, 50)

#define MOD1_TERRAIN_NOISE_B				MOD1_DISABLE
#define MOD1_TERRAIN_NOISE_B_FREQUENCY		10
#define MOD1_TERRAIN_NOISE_B_RANGE			100
#define MOD1_TERRAIN_NOISE_B_OFFSET			point2<float>(0)

//											WATER

#define MOD1_WATER_FLOOD_BORDER

#define MOD1_WATER_CONST_A					0.5
#define MOD1_WATER_CONST_g					10
#define MOD1_WATER_CONST_dt					3

#define MOD1_WATER_HIDDEN					std::numeric_limits<float>::min()
#define MOD1_WATER_INDENT					-100

#define MOD1_WATER_COLOR_A					0, 0.62, 1
#define MOD1_WATER_COLOR_B					0, 0.05, 0.1
#define MOD1_WATER_COLOR_RANGE				200