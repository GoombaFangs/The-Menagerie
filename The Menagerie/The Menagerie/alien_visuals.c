#include "alien_visuals.h"


void print_alien_art(const Alien* alien, int index)
{
    printf(" Alien %d \n", index + 1);
    print_species_art(alien->species);
    printf("species: %s\n\n", alien->species);
}

void print_species_art(const char* species) 
{
	int variant = 0;
    if (strcmp(species, "flying") == 0) 
    {
        variant = rand() % 10;
        print_flying(variant);
           
    }
    else if (strcmp(species, "aquatic") == 0)
    {
        variant = rand() % 10;
        print_aquatic(variant);
    }
    else if (strcmp(species, "crawler") == 0) 
    {
        variant = rand() % 10;
        print_crawler(variant);
    }
    else if (strcmp(species, "glowing") == 0) 
    {
        variant = rand() % 1;
		print_glowing(variant);
    }
    else if (strcmp(species, "camouflaged") == 0) 
    {
        variant = rand() % 2;
        print_camouflaged(variant);
    }
    else if (strcmp(species, "rocky") == 0)
    {
        variant = rand() % 1;
        print_rocky(variant);
    }
    else if (strcmp(species, "gas_based") == 0) 
    {
        variant = rand() % 1;
        print_gas_based(variant);
    }
    else {
        printf(
            "    .-''''-.\n"
            "   /        \\\n"
            "  |  UNKNOWN |\n"
            "   \\________/\n"
        );
    }
}

void print_alien_card(const Alien* alien, int index) 
{
    printf("+--------- Alien %d ---------+\n", index + 1);
    printf("| Species  : %-15s |\n", alien->species);
    printf("| Sex      : %-15c |\n", alien->sex);
    printf("| Age      : %-15d |\n", alien->age);
    printf("| Size     : %-15s |\n", alien->size);
    printf("| Diet     : %-15s |\n", alien->diet);
    printf("| Nickname : %-15s |\n", alien->nickname[0] ? alien->nickname : "(none)");
    printf("+----------------------------+\n\n");
}