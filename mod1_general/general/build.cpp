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
MOD1_GENERATE_MESSAGE("Mod1 General : Terrain object is built")
#endif

#if MOD1_ENABLED(MOD1_GENERAL_USE_WATER)
	add_model(MOD1_INTERNAL(water)->model());
MOD1_GENERATE_MESSAGE("Mod1 General : Water object is built")
#endif

//						SCENARIOS PREPARATION

	point2<int>			rain_range = MOD1_INTERNAL(water)->size() - point2<int>(2);
	point2<int>			spring_range = MOD1_INTERNAL(water)->size() - MOD1_GENERAL_WELL_SIZE;

	rain_distribution_x = std::uniform_int_distribution<int>(0, rain_range.x);
	rain_distribution_y = std::uniform_int_distribution<int>(0, rain_range.y);

	well_distribution_x = std::uniform_int_distribution<int>(0, spring_range.x);
	well_distribution_y = std::uniform_int_distribution<int>(0, spring_range.y);

//						INITIAL HINT

	hint_init(window_width() / 2, window_height() * 8 / 10, "Drag mouse to rotate terrain", font_gill_sans, 4);
	hint_drag = true;
}