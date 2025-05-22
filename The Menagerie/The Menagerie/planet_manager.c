#include "planet_manager.h"


void generate_random_name(char* name, int max_length)
{
    const char* syllables[] = 
    {
        "za", "tor", "ex", "lun", "kir", "von", "rax", "shi", "ka", "mi",
        "dra", "xel", "vor", "qu", "zen", "tha", "jo", "rek", "nu", "sol",
        "zor", "lek", "tri", "val", "nor", "bel", "pha", "kra", "sil", "mar",
        "ion", "zer", "nek", "gol", "tas", "ru", "ish", "vek", "tia", "mon",
        "elu", "sar", "kim", "dro", "ani", "lor", "bem", "ush", "zan", "yor",
        "nex", "il", "pri", "dak", "ash", "thy", "omo", "gal", "rik", "su"
    };

    const int num_syllables = sizeof(syllables) / sizeof(syllables[0]);
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

Planet travel_to_planet(Planet planet_selected)
{
    for (int i = 0; i < num_terrain; i++)
    {
        if (strcmp(planet_selected.terrain, terrain_list[i]) == 0)
        {
            return planet_selected;
        }
    }
    Planet default_planet = { "Unknown", 0.0, "Unknown" };
    return default_planet;
}