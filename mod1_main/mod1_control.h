#pragma once

#include "mod1_macros.h"

//											GLOBAL

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
#define MOD1_SHOW_BACK_OF_POLYGON			MOD1_DISABLE
#define MOD1_SRGB							MOD1_DISABLE

#define MOD1_LIGHT_AMBIENT_INTENSITY		0.2
#define MOD1_LIGHT_POINT_INTENSITY			0.8
#define MOD1_LIGHT_POINT_POSITION			0, 30, 0

#define MOD1_LIGHT_CUBE						MOD1_ENABLE
#define MOD1_LIGHT_CUBE_SIDE				5

#define MOD1_CAMERA_POSITION				glm::vec3(20, 20, 50)
#define MOD1_CAMERA_MOVEMENT_SPEED			20
#define MOD1_CAMERA_ROTATION_SPEED			0.04

#define MOD1_BACKGROUND						point3<float>(0.8)

//											MAIN

#define MOD1_USE_TERRAIN					MOD1_ENABLE
#define MOD1_USE_WATER						MOD1_ENABLE

//											TERRAIN

#define MOD1_TERRAIN_HILLS					MOD1_ENABLE
#define MOD1_TERRAIN_NOISE					MOD1_DISABLE

#define MOD1_TERRAIN_NOISE_HILL				MOD1_ENABLE
#define MOD1_TERRAIN_NOISE_HILL_FREQUENCY	10
#define MOD1_TERRAIN_NOISE_HILL_RANGE		800
#define MOD1_TERRAIN_NOISE_HILL_OFFSET		point2<float>(0)
#define MOD1_TERRAIN_NOISE_HILL_ADD			0.8

#define MOD1_TERRAIN_NOISE_A				MOD1_ENABLE
#define MOD1_TERRAIN_NOISE_A_FREQUENCY		2
#define MOD1_TERRAIN_NOISE_A_RANGE			5000
#define MOD1_TERRAIN_NOISE_A_OFFSET			point2<float>(50, 50)

#define MOD1_TERRAIN_NOISE_B				MOD1_ENABLE
#define MOD1_TERRAIN_NOISE_B_FREQUENCY		10
#define MOD1_TERRAIN_NOISE_B_RANGE			100
#define MOD1_TERRAIN_NOISE_B_OFFSET			point2<float>(0)

//											WATER

#define MOD1_WATER_FLOOD_BORDER

//#define MOD1_WATER_CONST_A					0.5
//#define MOD1_WATER_CONST_g					10
//#define MOD1_WATER_CONST_dt					0.1

#define MOD1_WATER_HIDDEN					-100

#define MOD1_WATER_COLOR_A					0, 0.62, 1
#define MOD1_WATER_COLOR_B					0, 0.05, 0.1
#define MOD1_WATER_COLOR_RANGE				50