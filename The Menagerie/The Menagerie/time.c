#include "time.h"

void hold_seconds(double second)
{
	clock_t start = clock();
	while (1)
	{
		clock_t end = clock();
		double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
		if (seconds >= second)
		{
			break;
		}
	}
}