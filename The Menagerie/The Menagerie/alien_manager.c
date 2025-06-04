#include "alien_manager.h"

Alien add_nickname(Alien* aliens, int selected_index, int* backspace)
{
    alien_card(aliens, selected_index);
    printf("English letters only!\n");
    printf("Enter a nickname for this alien:\n");

    int result = get_alpha_input(aliens[selected_index].nickname, sizeof(aliens[selected_index].nickname));

    if (backspace)
    {
        *backspace = result;
    }

    reset_console();
    return aliens[selected_index];
}

int get_alien_types_for_terrain(const char* terrain, AlienType* out_types)
{
    {
        if (strcmp(terrain, "ocean") == 0)
        {
            out_types[0] = ALIEN_AQUATIC;
            out_types[1] = ALIEN_GLOWING;
            return 2;
        }
        else if (strcmp(terrain, "desert") == 0)
        {
            out_types[0] = ALIEN_CRAWLER;
            out_types[1] = ALIEN_CAMOUFLAGED;
            return 2;
        }
        else if (strcmp(terrain, "forest") == 0)
        {
            out_types[0] = ALIEN_FLYING;
            out_types[1] = ALIEN_CAMOUFLAGED;
            return 2;
        }
        else if (strcmp(terrain, "swamp") == 0)
        {
            out_types[0] = ALIEN_GAS_BASED;
            out_types[1] = ALIEN_CRAWLER;
            return 2;
        }
        else if (strcmp(terrain, "mountain") == 0)
        {
            out_types[0] = ALIEN_ROCKY;
            out_types[1] = ALIEN_FLYING;
            return 2;
        }
        else if (strcmp(terrain, "volcanic") == 0)
        {
            out_types[0] = ALIEN_ROCKY;
            out_types[1] = ALIEN_AQUATIC;
            return 2;
        }
        else if (strcmp(terrain, "icy") == 0)
        {
            out_types[0] = ALIEN_AQUATIC;
            out_types[1] = ALIEN_CRAWLER;
            return 2;
        }
        else if (strcmp(terrain, "gas") == 0)
        {
            out_types[0] = ALIEN_GAS_BASED;
            out_types[1] = ALIEN_GLOWING;
            return 2;
        }
        else if (strcmp(terrain, "urban ruins") == 0)
        {
            out_types[0] = ALIEN_CAMOUFLAGED;
            out_types[1] = ALIEN_ROCKY;
            return 2;
        }
        else if (strcmp(terrain, "crystal plains") == 0)
        {
            out_types[0] = ALIEN_GLOWING;
            out_types[1] = ALIEN_FLYING;
            return 2;
        }
        else if (strcmp(terrain, "sky island") == 0)
        {
            out_types[0] = ALIEN_FLYING;
            out_types[1] = ALIEN_CAMOUFLAGED;
            return 2;
        }
        else
        {
            return 0;
        }
    }
}

const char* get_alien_type_name(AlienType type)
{
    switch (type)
    {
    case ALIEN_FLYING: return "flying";
    case ALIEN_AQUATIC: return "aquatic";
    case ALIEN_CRAWLER: return "crawler";
    case ALIEN_GLOWING: return "glowing";
    case ALIEN_CAMOUFLAGED: return "camouflaged";
    case ALIEN_ROCKY: return "rocky";
    case ALIEN_GAS_BASED: return "gas_based";
    default: return "unknown";
    }
}

Alien* generate_aliens(char* planet_terrain, int count)
{
    if (count <= 0)
        return NULL;

    Alien* aliens = malloc(count * sizeof(Alien));
    if (!aliens)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    AlienType possible_types[2];
    int type_count = get_alien_types_for_terrain(planet_terrain, possible_types);
    if (type_count <= 0)
    {
        printf("Unknown terrain type: %s\n", planet_terrain);
        free(aliens);
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        aliens[i].type = possible_types[rand() % type_count];
        strcpy_s(aliens[i].species, sizeof(aliens[i].species), get_alien_type_name(aliens[i].type));
        aliens[i].sex = (rand() % 2 == 0) ? 'M' : 'F';
        aliens[i].age = rand() % 100 + 1;
        strcpy_s(aliens[i].size, sizeof(aliens[i].size), size_list[rand() % num_sizes]);
        strcpy_s(aliens[i].diet, sizeof(aliens[i].diet), diet_list[rand() % num_diets]);
        aliens[i].art_variant = rand() % 10;
        aliens[i].nickname[0] = '\0';
    }

    return aliens;
}