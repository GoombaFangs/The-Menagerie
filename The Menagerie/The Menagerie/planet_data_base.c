#include "planet_data_base.h"

const char* terrain_list[] =
{
    "ocean",
    "desert",
    "forest",
    "swamp",
    "mountain",
    "volcanic",
    "icy",
    "gas",
    "urban_ruins",
    "crystal_plains"
};

const int num_terrain = sizeof(terrain_list) / sizeof(terrain_list[0]);