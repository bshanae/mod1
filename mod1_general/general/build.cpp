#include "general.h"

void					general::build()
{
MOD1_GENERATE_MESSAGE("")

	MOD1_INTERNAL(terrain)->parse_map(first_argument);
	MOD1_INTERNAL(terrain)->parse_noise(second_argument ? second_argument : "");
	MOD1_INTERNAL(terrain)->build();

	MOD1_INTERNAL(water)->build();

#if MOD1_ENABLED(MOD1_GENERAL_USE_TERRAIN)
	add_model(MOD1_INTERNAL(terrain)->model());
MOD1_GENERATE_MESSAGE("Mod1 General : Terrain is built")
#endif

#if MOD1_ENABLED(MOD1_GENERAL_USE_WATER)
	add_model(MOD1_INTERNAL(water)->model());
MOD1_GENERATE_MESSAGE("Mod1 General : Water is built")
#endif

	point2<int>			range = MOD1_INTERNAL(water)->size() - point2<int>(1);

	distribution_water_x = std::uniform_int_distribution<int>(0, range.x);
	distribution_water_y = std::uniform_int_distribution<int>(0, range.y);
}