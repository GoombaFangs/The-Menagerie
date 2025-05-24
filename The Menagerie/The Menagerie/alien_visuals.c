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
void alien_card(Alien* aliens , int index)
{
    printf("+--------- Alien %d ---------+\n", index + 1);
    printf("                                    +----------------------------+\n");
    printf("                                    | Species  : %-15s |\n", get_alien_type_name(aliens[index].type));
    printf("                                    | Sex      : %-15c |\n", aliens[index].sex);
    printf("                                    | Age      : %-15d |\n", aliens[index].age);
    printf("                                    | Size     : %-15s |\n", aliens[index].size);
    printf("                                    | Diet     : %-15s |\n", aliens[index].diet);
    printf("                                    | Nickname : %-15s |\n", aliens[index].nickname[0] ? aliens[index].nickname : "(none)");
    printf("                                    +----------------------------+\n");
    print_alien_art(&aliens[index], index);
    printf("+----------------------------+\n\n");
}

void zoo_alien_card(Alien* aliens, int index)
{
    printf("Nickname : %-15s\n\n", aliens[index].nickname[0] ? aliens[index].nickname : "(none)");
    print_alien_art(&aliens[index], index);
}

void print_alien_options(Alien* aliens, int count, int selected, int visible_count)
{
    reset_console();
    printf("Key binding  :   [^] Up    [v] Down    [ESC] Back / Exit    [ Enter ] Confirm\n\n");
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
        printf("            [^]  %d\n\n", start);
    }

    for (int i = start; i < start + visible_count && i < count; i++)
    {
        alien_card(aliens, i);
    }

    if (start + visible_count < count)
    {
        printf("            [v]  %d\n", (count - start - 1));
    }
    printf("\n\n\n   Choose an Alien\n");
}