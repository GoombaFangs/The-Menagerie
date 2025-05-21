#include "alien_visuals.h"


void print_alien_art(const Alien* alien, int index)
{
    print_species_art(alien->species , alien->art_variant);
    printf("\n\n\n");
}

void print_species_art(const char* species, int variant)
{
    if (strcmp(species, "flying") == 0) print_flying(variant);
    else if (strcmp(species, "aquatic") == 0) print_aquatic(variant);
    else if (strcmp(species, "crawler") == 0)  print_crawler(variant);
    else if (strcmp(species, "glowing") == 0) print_glowing(variant);
    else if (strcmp(species, "camouflaged") == 0) print_camouflaged(variant);
    else if (strcmp(species, "rocky") == 0) print_rocky(variant);
    else if (strcmp(species, "gas_based") == 0) print_gas_based(variant);
    else 
    {
        printf(
            "    .-''''-.\n"
            "   /        \\\n"
            "  |  UNKNOWN |\n"
            "   \\________/\n"
        );
    }
}