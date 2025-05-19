#include "alien_visuals.h"


void print_alien_art(const alien* alien, int index)
{
    print_species_art(alien->species);
    printf("\n\n\n\n                   %s\n", alien->species);
}

void print_species_art(const char* species) 
{
    if (strcmp(species, "flying") == 0) 
    {
		static int variant = 0;
        if (variant == 0) 
        {
            variant = rand() % 10;
        }
        print_flying(variant);    
    }
    else if (strcmp(species, "aquatic") == 0)
    {
        static int variant = 0;
        if (variant == 0)
        {
            variant = rand() % 10;
        }
        print_aquatic(variant);
    }
    else if (strcmp(species, "crawler") == 0) 
    {
        static int variant = 0;
        if (variant == 0)
        {
            variant = rand() % 10;
        }
        print_crawler(variant);
    }
    else if (strcmp(species, "glowing") == 0) 
    {
        static int variant = 0;
        if (variant == 0)
        {
            variant = rand() % 1;
        }
		print_glowing(variant);
    }
    else if (strcmp(species, "camouflaged") == 0) 
    {
        static int variant = 0;
        if (variant == 0)
        {
            variant = rand() % 2;
        }
        print_camouflaged(variant);
    }
    else if (strcmp(species, "rocky") == 0)
    {
        static int variant = 0;
        if (variant == 0)
        {
            variant = rand() % 1;
        }
        print_rocky(variant);
    }
    else if (strcmp(species, "gas_based") == 0) 
    {
        static int variant = 0;
        if (variant == 0)
        {
            variant = rand() % 1;
        }
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