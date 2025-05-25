#include "planet_manager.h"

#define VISITS_PER_PAGE 10// for planet log

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

PlanetVisit* visited_planets = NULL;
int num_visited_planets = 0;
int visited_capacity = 0;

void planet_log()
{
    int selected = 0;
    int current_page = 0;

    while (1)
    {
        reset_console();
        print_small_window();

        if (num_visited_planets == 0)
        {
            printf("\n                                     No planets visited yet.\n");
        }
        else
        {
            int total_pages = (num_visited_planets + VISITS_PER_PAGE - 1) / VISITS_PER_PAGE;
            if (current_page >= total_pages)
                current_page = total_pages - 1;

            int start = current_page * VISITS_PER_PAGE;
            int end = start + VISITS_PER_PAGE;
            if (end > num_visited_planets) end = num_visited_planets;

            printf("\n                         [<]/[>] Page | [Enter]/[Esc] Exit\n\n");
            printf("\n\n     Planet Log (Page %d/%d)\n\n", current_page + 1, total_pages);
            printf("     ----------------------------------------\n");

            for (int i = start; i < end; ++i)
            {
                PlanetVisit visit = visited_planets[i];
                printf("      %2d. Planet: %s | Terrain: %s | Distance: %.1f ly\n",
                    i + 1, visit.planet.name, visit.planet.terrain, visit.planet.distance / 4);
                printf("                   Alien: %s | Type: %s\n",
                    visit.alien.nickname[0] ? visit.alien.nickname : "[NO NAME]",
                    get_alien_type_name(visit.alien.type));
                printf("     ----------------------------------------\n");
            }
        }

        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

        if (key == 75 && current_page > 0) // LEFT
            current_page--;
        else if (key == 77 && (current_page + 1) * VISITS_PER_PAGE < num_visited_planets) // RIGHT
            current_page++;
        else if (key == 13 || key == 27) // ENTER or ESC
            break;
    }
}

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