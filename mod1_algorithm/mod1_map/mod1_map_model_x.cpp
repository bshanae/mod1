#include "mod1_map.h"

static int 					gcd(int a, int b)
{
	return (a ? gcd(b % a, a) : b);
}

void 						mod1_map::model_update_delta(const int &i, const int &j, const int &index)
{
	float 					temp_delta;

	temp_delta = fabsf(source_data[i][index] - source_data[j][index]);
	model_delta = gcd(model_delta, (int)temp_delta);
}

void						mod1_map::model_prepare()
{
	model_delta = 0;

	for (int i = 0; i < source_data.size(); i++)
		for (int j = 0; j < source_data.size(); j++)
		{
			if (j == i)
				continue ;
			model_update_delta(i, j, 0);
			model_update_delta(i, j, 1);
		}

	printf("model delta = %d\n", model_delta);

}

void						mod1_map::model_build()
{
	model_prepare();
}
