#include "planet_save_load.h"

void save_planet_to_file(const PlanetLog* log)
{
    if (!log || !log->visits || log->count == 0)
        return;

    save_data("planet_visits_count.txt", &log->count, sizeof(int), 1);
    save_data("planet_visits_array.txt", log->visits, sizeof(PlanetVisit), log->count);
}

void load_planet_from_file(PlanetLog* log)
{
    if (!log)
        return;

    int count = 0;
    load_data("planet_visits_count.txt", &count, sizeof(int), 1);

    int capacity = (count > 0) ? count : 10;
    PlanetVisit* buffer = malloc(capacity * sizeof(PlanetVisit));
    if (!buffer)
    {
        printf("Failed to allocate memory for planet visits.\n");
        exit(1);
    }

    int success = load_data("planet_visits_array.txt", buffer, sizeof(PlanetVisit), count);

    log->visits = buffer;
    log->count = success ? count : 0;
    log->capacity = capacity;
}

void free_planet(PlanetLog* log)
{
    if (log && log->visits)
    {
        free(log->visits);
        log->visits = NULL;
        log->count = 0;
        log->capacity = 0;
    }
}