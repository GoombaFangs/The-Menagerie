#include "alien_visuals.h"


void print_alien_art(const Alien* alien, int index)
{
    const char* type_name = get_alien_type_name(alien->type);
    print_species_art(type_name, alien->art_variant);
    printf("\n\n\n");
}

void print_species_art(const char* type, int variant)
{
    if (strcmp(type, "flying") == 0) print_flying(variant);
    else if (strcmp(type, "aquatic") == 0) print_aquatic(variant);
    else if (strcmp(type, "crawler") == 0)  print_crawler(variant);
    else if (strcmp(type, "glowing") == 0) print_glowing(variant);
    else if (strcmp(type, "camouflaged") == 0) print_camouflaged(variant);
    else if (strcmp(type, "rocky") == 0) print_rocky(variant);
    else if (strcmp(type, "gas_based") == 0) print_gas_based(variant);
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

void print_alien_options(Alien* aliens, int count, int selected, int visible_count)
{
    reset_console();
    printf("\n\n");

    int start = 0;
    if (count > visible_count)
    {
        if (selected < visible_count / 2)
            start = 0;
        else if (selected > count - (visible_count + 1) / 2)
            start = count - visible_count;
        else
            start = selected - visible_count / 2;
    }

    if (start > 0)
    {
        printf("           %d aliens above press up to show\n\n", start);
    }

    for (int i = start; i < start + visible_count && i < count; i++)
    {
        printf("+--------- Alien %d ---------+\n", i + 1);
        printf("                                    +----------------------------+\n");
        printf("                                    | Species  : %-15s |\n", get_alien_type_name(aliens[i].type));
        printf("                                    | Sex      : %-15c |\n", aliens[i].sex);
        printf("                                    | Age      : %-15d |\n", aliens[i].age);
        printf("                                    | Size     : %-15s |\n", aliens[i].size);
        printf("                                    | Diet     : %-15s |\n", aliens[i].diet);
        printf("                                    | Nickname : %-15s |\n", aliens[i].nickname[0] ? aliens[i].nickname : "(none)");
        printf("                                    +----------------------------+\n");
        print_alien_art(&aliens[i], i);
        //if (i == selected)
        //    printf("                         <<< SELECTED >>>\n");
        printf("+----------------------------+\n\n");
    }

    if (start + visible_count < count)
    {
        printf("           %d aliens below press down to show\n", (count - start - 1));
    }
}