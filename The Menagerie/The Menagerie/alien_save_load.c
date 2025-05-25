#include "alien_save_load.h"

void save_aliens_to_file(const Zoo* zoo)
{
    save_data("zoo_capacity.txt", &zoo->capacity, sizeof(int), 1);
    save_data("zoo_count.txt", &zoo->count, sizeof(int), 1);
    save_data("zoo_array.txt", zoo->list, sizeof(Alien), zoo->count);
}

void load_aliens_from_file(Zoo* zoo)
{
    load_data("zoo_count.txt", &zoo->count, sizeof(int), 1);
    load_data("zoo_capacity.txt", &zoo->capacity, sizeof(int), 1);
    zoo->list = malloc(zoo->capacity * sizeof(Alien));
    if (zoo->list)
    {
        load_data("zoo_array.txt", zoo->list, sizeof(Alien), zoo->count);
    }
}