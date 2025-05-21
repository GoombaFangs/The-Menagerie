#include "planet_manager.h"

Planet* generate_planet(int count)
{
    if (count <= 0)
    {
        return NULL;
    }

    Planet* planets = malloc(count * sizeof(Planet));
    if (planets == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        planets[i].distance = 100.0 + ((double)rand() / RAND_MAX) * (10000.0 - 100.0); // Random distance between 100.0 and 10000.0
        strcpy_s(planets[i].terrain, sizeof(planets[i].terrain), terrain_list[rand() % num_terrain]);
		planets[i].hasLife = rand() % 2; 
		if (planets[i].hasLife)
		{
			printf("Planet %d has life.\n", i + 1);
		}
		else
		{
			printf("Planet %d does not have life.\n", i + 1);
		}
    }
    return planets;
}