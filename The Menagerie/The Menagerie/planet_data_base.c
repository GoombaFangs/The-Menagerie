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
    "urban ruins",
    "crystal plains"
};

const char* syllables[] =
{
    "za", "tor", "ex", "lun", "kir", "von", "rax", "shi", "ka", "mi",
    "dra", "xel", "vor", "qu", "zen", "tha", "jo", "rek", "nu", "sol",
    "zor", "lek", "tri", "val", "nor", "bel", "pha", "kra", "sil", "mar",
    "ion", "zer", "nek", "gol", "tas", "ru", "ish", "vek", "tia", "mon",
    "elu", "sar", "kim", "dro", "ani", "lor", "bem", "ush", "zan", "yor",
    "nex", "il", "pri", "dak", "ash", "thy", "omo", "gal", "rik", "su"
};

const int num_terrain = sizeof(terrain_list) / sizeof(terrain_list[0]);
const int num_syllables = sizeof(syllables) / sizeof(syllables[0]);