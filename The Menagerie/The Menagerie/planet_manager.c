#include "planet_manager.h"

PlanetVisit* visited_planets = NULL;
int num_visited_planets = 0;
int visited_capacity = 0;

void add_planet_visit(Planet planet, Alien alien)
{
    if (num_visited_planets >= visited_capacity)
    {
        visited_capacity = (visited_capacity == 0) ? 10 : visited_capacity * 2;

        PlanetVisit* temp = realloc(visited_planets, visited_capacity * sizeof(PlanetVisit));
        if (!temp)
        {
            printf("Failed to allocate memory for visited planets.\n");
            exit(1);
        }

        visited_planets = temp;
    }

    visited_planets[num_visited_planets++] = (PlanetVisit){ planet, alien };
}

void generate_random_name(char* name, int max_length)
{
    int num_parts = 1 + rand() % 3; // 1 to 3 syllables

    name[0] = '\0';

    for (int i = 0; i < num_parts; i++)
    {
        const char* syllable = syllables[rand() % num_syllables];

        if (strlen(name) + strlen(syllable) + 1 >= max_length)
            break;

        strcat_s(name, max_length, syllable);
    }

    name[0] = toupper(name[0]);
}

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
        generate_random_name(planets[i].name, sizeof(planets[i].name));
        planets[i].distance = 100.0 + ((double)rand() / RAND_MAX) * (10000.0 - 100.0); // Random distance between 100.0 and 10000.0
        strcpy_s(planets[i].terrain, sizeof(planets[i].terrain), terrain_list[rand() % num_terrain]);
    }
    return planets;
}
