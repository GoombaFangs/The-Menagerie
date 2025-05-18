#include "alien_data_base.h"

const char* species_list[] = 
{
    "flying",
    "aquatic",
    "crawler",
    "glowing",
    "camouflaged",
    "rocky",
    "gas_based"
};

const char* size_list[] = 
{
    "small",
    "medium",
    "large",
    "huge"
};

const char* diet_list[] = 
{
    "fruits",
    "meat",
    "plants",
    "minerals"
};

const int num_species = sizeof(species_list) / sizeof(species_list[0]);
const int num_sizes = sizeof(size_list) / sizeof(size_list[0]);
const int num_diets = sizeof(diet_list) / sizeof(diet_list[0]);