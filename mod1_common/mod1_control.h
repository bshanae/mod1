#pragma once

#include "mod1_definition.h"

//												GLOBAL

#define MOD1_DEVELOPER_MODE						MOD1_ENABLE

#define MOD1_WINDOW_WIDTH						1028
#define MOD1_WINDOW_HEIGHT						720
#define MOD1_WINDOW_NAME						""

//												ENGINE GL

#define MOD1_SRGB								MOD1_DISABLE

#define MOD1_CAMERA_POSITION					500, 300, 1200
#define MOD1_CAMERA_MOVEMENT_SPEED				20
#define MOD1_CAMERA_ROTATION_SPEED				0.04
#define MOD1_CAMERA_ZOOM_SPEED					0.05
#define MOD1_CAMERA_NEAR_PLANE					100.f
#define MOD1_CAMERA_FAR_PLANE					2500.f

//												ALGORITHM

#define MOD1_TERRAIN_START						point2<float>(-500, -500)
#define MOD1_TERRAIN_END						point2<float>(+500, +500)
#define MOD1_TERRAIN_DELTA						10
#define MOD1_TERRAIN_INDENT						0.3

#define MOD1_WATER_CONST_A						0.5
#define MOD1_WATER_CONST_g						10
#define MOD1_WATER_CONST_dt						3

#define MOD1_WATER_AMBIENT_RECEPTIVITY			1.2
#define MOD1_WATER_DIFFUSE_RECEPTIVITY			0.8
#define MOD1_WATER_SPECULAR_RECEPTIVITY			0.2

#define MOD1_WATER_RANGE_MULTIPLIER				1.2

#define MOD1_WATER_MINIMUM						0.05
#define MOD1_WATER_HIDDEN						-100

//												GUI

#define MOD1_FONT_SIZE							128

#define MOD1_GUI_PROGRAM_TEXT_VERTEX			"source_gl/text_vertex.glsl"
#define MOD1_GUI_PROGRAM_TEXT_FRAGMENT			"source_gl/text_fragment.glsl"

//												GENERAL

#define MOD1_GENERAL_USE_TERRAIN				MOD1_ENABLE
#define MOD1_GENERAL_USE_WATER					MOD1_ENABLE

#define MOD1_GENERAL_PROGRAM_MAIN_VERTEX		"source_gl/main_vertex.glsl"
#define MOD1_GENERAL_PROGRAM_MAIN_FRAGMENT		"source_gl/main_fragment.glsl"

#define MOD1_GENERAL_PROGRAM_BLUR_VERTEX		"source_gl/blur_vertex.glsl"
#define MOD1_GENERAL_PROGRAM_BLUR_FRAGMENT		"source_gl/blur_fragment.glsl"

#define MOD1_GENERAL_GILL_SANS					"source_gui/GillSans.ttc"
#define MOD1_GENERAL_HELVETICA_NEUE				"source_gui/HelveticaNeue.ttc"

#define MOD1_GENERAL_LIGHT_AMBIENT_INTENSITY	0.2
#define MOD1_GENERAL_LIGHT_DIRECT_DIRECTION		0, -1, 0
#define MOD1_GENERAL_LIGHT_DIRECT_INTENSITY		0.8

#define MOD1_GENERAL_BIG_WAVE_HEIGHT			150
#define MOD1_GENERAL_BIG_WAVE_WIDTH				15

#define MOD1_GENERAL_LITTLE_WAVE_HEIGHT			150
#define MOD1_GENERAL_LITTLE_WAVE_WIDTH			5

#define MOD1_GENERAL_WELL_SIZE					mod1_engine_gl::point2<int>(5, 5)
#define MOD1_GENERAL_WELL_VOLUME				10

#define MOD1_GENERAL_RAINDROP_VOLUME			10

#define MOD1_GENERAL_BACKGROUND					mod1_engine_gl::point3<float>(0.8f)