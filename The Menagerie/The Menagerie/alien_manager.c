#include "alien_manager.h"

Alien* generate_aliens(char* planet_terrain, int count)
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
        //strcpy_s(aliens[i].species, sizeof(aliens[i].species), "gas_based");
        strcpy_s(aliens[i].species, sizeof(aliens[i].species), species_list[rand() % num_species]);
        aliens[i].sex = (rand() % 2 == 0) ? 'M' : 'F';
        aliens[i].age = rand() % 100 + 1;
        strcpy_s(aliens[i].size, sizeof(aliens[i].size), size_list[rand() % num_sizes]);
        strcpy_s(aliens[i].diet, sizeof(aliens[i].diet), diet_list[rand() % num_diets]);
        aliens[i].nickname[0] = '\0';
    }

    return aliens;
}

void alien_card(const Alien* alien, int count, int selected)
{
    if (count = selected)
    {
        printf("\n\n\n+--------- Alien %d ---------+", 1);
        printf("       +----------------------------+\n");
        printf("                                    | Species  : %-15s |\n", alien[1].species);
        printf("                                    | Sex      : %-15c |\n", alien[1].sex);
        printf("                                    | Age      : %-15d |\n", alien[1].age);
        printf("                                    | Size     : %-15s |\n", alien[1].size);
        printf("                                    | Diet     : %-15s |\n", alien[1].diet);
        printf("                                    | Nickname : %-15s |\n", alien[1].nickname[0] ? alien->nickname : "(none)");
        printf("                                    +----------------------------+\n");
        print_alien_art(&alien[1], 1);
        printf("+----------------------------+\n\n\n\n");
    }
    for (int i = 1; i < count; i++)
    {
        printf("+--------- Alien %d ---------+", i + 1);
        printf("       +----------------------------+\n");
        printf("                                    | Species  : %-15s |\n", alien[i].species);
        printf("                                    | Sex      : %-15c |\n", alien[i].sex);
        printf("                                    | Age      : %-15d |\n", alien[i].age);
        printf("                                    | Size     : %-15s |\n", alien[i].size);
        printf("                                    | Diet     : %-15s |\n", alien[i].diet);
        printf("                                    | Nickname : %-15s |\n", alien[i].nickname[0] ? alien->nickname : "(none)");
        printf("                                    +----------------------------+\n");
        print_alien_art(&alien[i], i);
        printf("+----------------------------+\n\n\n\n");
    }
}