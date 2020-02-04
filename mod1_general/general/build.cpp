#include "general.h"

void					general::build()
{
	MOD1_INTERNAL(terrain)->parse(first_argument);
	MOD1_INTERNAL(terrain)->build();
	MOD1_INTERNAL(water)->build();

#if MOD1_ENABLED(MOD1_USE_TERRAIN)
	add_model(MOD1_INTERNAL(terrain)->model());
#endif

#if MOD1_ENABLED(MOD1_USE_WATER)
	add_model(MOD1_INTERNAL(water)->model());
#endif
}