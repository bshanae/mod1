#pragma once

#define MOD1_DISABLE			0
#define MOD1_ENABLE				1

#define MOD1_ENABLED(x)			x == 1
#define MOD1_DISABLED(x)		x == 0

#define MOD1_MIN(a, b)			((a) < (b) ? (a) : (b))
#define MOD1_MAX(a, b)			((a) > (b) ? (a) : (b))