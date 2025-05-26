#include "planet_manager.h"

#define INITIAL_PLANET_CAPACITY 10

void add_planet_visit(PlanetLog* log, Planet planet, Alien alien)
{
    if (!log) return;

    if (log->count >= log->capacity)
    {
        int new_capacity = (log->capacity == 0) ? INITIAL_PLANET_CAPACITY : log->capacity * 2;
        PlanetVisit* temp = realloc(log->visits, new_capacity * sizeof(PlanetVisit));

        if (!temp)
        {
            printf("Failed to allocate memory for visited planets.\n");
            exit(1);
        }

        log->visits = temp;
        log->capacity = new_capacity;
    }

    log->visits[log->count++] = (PlanetVisit){ planet, alien };
}

void generate_random_name(char* name, int max_length)
{
    if (!name || max_length <= 1) return;

    int num_parts = 1 + rand() % 3; // 1 to 3 syllables
    name[0] = '\0';

    for (int i = 0; i < num_parts; ++i)
    {
        const char* syllable = syllables[rand() % num_syllables];

        if ((int)(strlen(name) + strlen(syllable) + 1) >= max_length)
            break;

        strcat_s(name, max_length, syllable);
    }

    name[0] = toupper(name[0]);
}

Planet* generate_planet(int count)
{
    if (count <= 0) return NULL;

    Planet* planets = malloc(count * sizeof(Planet));
    if (!planets)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < count; ++i)
    {
        generate_random_name(planets[i].name, sizeof(planets[i].name));
        planets[i].distance = 100.0 + ((double)rand() / RAND_MAX) * 9900.0;
        strcpy_s(planets[i].terrain, sizeof(planets[i].terrain), terrain_list[rand() % num_terrain]);
    }

    return planets;
}
