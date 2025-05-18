#include "AlienDataBase.h"

const char* species_list[] = 
{
    "Flying",
    "Aquatic",
    "Crawler",
    "Quadruped",
    "Glowing",
    "Camouflaged",
    "Rocky",
    "Gas-Based"
};

const char* size_list[] = 
{
    "Small",
    "Medium",
    "Large",
    "Huge"
};

const char* diet_list[] = 
{
    "Fruits",
    "Meat",
    "Plants",
    "Minerals"
};

const int num_species = sizeof(species_list) / sizeof(species_list[0]);
const int num_sizes = sizeof(size_list) / sizeof(size_list[0]);
const int num_diets = sizeof(diet_list) / sizeof(diet_list[0]);