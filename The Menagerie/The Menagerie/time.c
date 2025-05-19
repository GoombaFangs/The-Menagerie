#include "time.h"

int hold_seconds(double second)
{
	clock_t start = clock();
	while (1)
	{
		if (_kbhit())
		{
			return 0; 
		}

		clock_t end = clock();
		double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
		if (seconds >= second)
		{
			return 1;
		}
	}
}