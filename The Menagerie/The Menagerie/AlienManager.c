#include "AlienManager.h"

Alien* generate_aliens(int count)
{
    if (count <= 0)
    {
        return NULL;
    }

    Alien* aliens = malloc(count * sizeof(Alien));
    if (aliens == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        strcpy_s(aliens[i].species, sizeof(aliens[i].species), "Crawler");
        //strcpy_s(aliens[i].species, sizeof(aliens[i].species), species_list[rand() % num_species]);
        aliens[i].sex = (rand() % 2 == 0) ? 'M' : 'F';
        aliens[i].age = rand() % 100 + 1;
        strcpy_s(aliens[i].size, sizeof(aliens[i].size), size_list[rand() % num_sizes]);
        strcpy_s(aliens[i].diet, sizeof(aliens[i].diet), diet_list[rand() % num_diets]);
        aliens[i].nickname[0] = '\0';
    }

    return aliens;
}