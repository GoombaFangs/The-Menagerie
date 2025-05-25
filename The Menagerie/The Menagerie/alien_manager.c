#include "alien_manager.h"

// for alien_log
#define NUM_TYPES 7
#define VARIANTS_PER_TYPE 10
#define ALIENS_PER_PAGE 2

int get_alien_types_for_terrain(const char* terrain, AlienType* out_types)
{
    if (strcmp(terrain, "ocean") == 0)
    {
        out_types[0] = ALIEN_AQUATIC;
        out_types[1] = ALIEN_GLOWING;
    }
    else if (strcmp(terrain, "desert") == 0)
    {
        out_types[0] = ALIEN_CRAWLER;
        out_types[1] = ALIEN_CAMOUFLAGED;
    }
    else if (strcmp(terrain, "forest") == 0)
    {
        out_types[0] = ALIEN_CAMOUFLAGED;
        out_types[1] = ALIEN_FLYING;
    }
    else if (strcmp(terrain, "swamp") == 0)
    {
        out_types[0] = ALIEN_CRAWLER;
        out_types[1] = ALIEN_GLOWING;
    }
    else if (strcmp(terrain, "mountain") == 0)
    {
        out_types[0] = ALIEN_FLYING;
        out_types[1] = ALIEN_ROCKY;
    }
    else if (strcmp(terrain, "volcanic") == 0)
    {
        out_types[0] = ALIEN_ROCKY;
        out_types[1] = ALIEN_GLOWING;
    }
    else if (strcmp(terrain, "icy") == 0)
    {
        out_types[0] = ALIEN_GLOWING;
        out_types[1] = ALIEN_CRAWLER;
    }
    else if (strcmp(terrain, "gas") == 0)
    {
        out_types[0] = ALIEN_GAS_BASED;
        out_types[1] = ALIEN_GLOWING;
    }
    else if (strcmp(terrain, "urban ruins") == 0)
    {
        out_types[0] = ALIEN_CAMOUFLAGED;
        out_types[1] = ALIEN_CRAWLER;
    }
    else if (strcmp(terrain, "crystal plains") == 0)
    {
        out_types[0] = ALIEN_GLOWING;
        out_types[1] = ALIEN_FLYING;
    }
    else
    {
        return 0;
    }

    return 1;
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

Alien add_nickname(Alien* aliens, int selected_index, int* backspace)
{
    alien_card(aliens, selected_index);
    printf("\n  Enter a nickname for this alien:  \n");
    printf("  English letters only              \n\n");


    int result = get_alpha_input(aliens[selected_index].nickname, sizeof(aliens[selected_index].nickname));
    if (backspace)
    {
        *backspace = result;
    }
 
    reset_console();
    return aliens[selected_index];
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
    if (!get_alien_types_for_terrain(planet_terrain, possible_types))
    {
        printf("Unknown terrain type: %s\n", planet_terrain);
        free(aliens);
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        aliens[i].type = possible_types[rand() % 2];
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

void alien_log(const Zoo* zoo)
{

    int selected_type = 0;
    int current_page = 0;

    while (1)
    {
        reset_console();

        AlienType type = (AlienType)selected_type;
        const char* type_name = get_alien_type_name(type);

        // Count how many aliens were found
        int found_count = 0;
        for (int v = 0; v < VARIANTS_PER_TYPE; ++v)
        {
            Alien dummy;
            if (find_alien_in_zoo(zoo, type, v, &dummy))
                found_count++;
        }

        int total_pages = (VARIANTS_PER_TYPE + ALIENS_PER_PAGE - 1) / ALIENS_PER_PAGE;
        if (current_page >= total_pages)
            current_page = total_pages - 1;

		print_small_window();
        printf("\n                       [^]/[v] Category | [<]/[>] Page | [Enter/Esc] Exit\n\n");
        pirnt_alien_type_title(type);
        printf("\n                                       [%d/%d collected]   \n", found_count, VARIANTS_PER_TYPE);

        int start_variant = current_page * ALIENS_PER_PAGE;
        int end_variant = start_variant + ALIENS_PER_PAGE;
        if (end_variant > VARIANTS_PER_TYPE)
            end_variant = VARIANTS_PER_TYPE;

        for (int v = start_variant; v < end_variant; ++v)
        {
            Alien found;
            if (find_alien_in_zoo(zoo, type, v, &found))
            {
                printf("Alien %s-%d: [%s]\n", type_name, v + 1, found.nickname);
                print_alien_art(&found, v);
            }
            else
            {
                printf("Alien %s-%d: [UNKNOWN]\n", type_name, v + 1);
                print_species_art("unknown", 0);
            }
            printf("\n");
        }

        int missing = VARIANTS_PER_TYPE - found_count;
        if (missing == 0)
        {
            printf("All aliens collected in this category!\n\n");
        }

        printf("\n  Page %d/%d\n",current_page + 1, total_pages);

        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

		if (key == 72 && selected_type > 0) // UP
        {
            selected_type--;
            current_page = 0;
        }
		else if (key == 80 && selected_type < NUM_TYPES - 1) // DOWN
        {
            selected_type++;
            current_page = 0;
        }
        else if (key == 75 && current_page > 0)// LEFT
        {
            current_page--;
        }
		else if (key == 77 && current_page < total_pages - 1) // RIGHT
        {
            current_page++;
        }
		else if (key == 27 || key == 13)  // ESC or ENTER
        {
			break;
        }
    }
}