#include "planet_save_load.h"

void save_planet_visits_to_file()
{
    save_data("planet_visits_count.txt", &num_visited_planets, sizeof(int), 1);
    save_data("planet_visits_array.txt", visited_planets, sizeof(PlanetVisit), num_visited_planets);
}

void load_planet_visits_from_file()
{
    load_data("planet_visits_count.txt", &num_visited_planets, sizeof(int), 1);
    visited_capacity = num_visited_planets > 0 ? num_visited_planets : 10;
    visited_planets = malloc(visited_capacity * sizeof(PlanetVisit));
    if (visited_planets)
    {
        load_data("planet_visits_array.txt", visited_planets, sizeof(PlanetVisit), num_visited_planets);
    }
}