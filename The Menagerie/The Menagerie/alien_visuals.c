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

void pirnt_alien_type_title(AlienType type)
{
    switch (type)
    {
	case ALIEN_FLYING:
		printf("                                _____ _  __   _____ _   _  ____ \n");
		printf("                               |  ___| | \\ \\ / /_ _| \\ | |/ ___|\n");
		printf("                               | |_  | |  \\ V / | ||  \\| | |  _ \n");
		printf("                               |  _| | |___| |  | || |\\  | |_| |\n");
		printf("                               |_|   |_____|_| |___|_| \\_|\\____|\n");
		break;

	case ALIEN_AQUATIC:
        printf("                                _    ___  _   _   _  _____ ___ ____ \n");
        printf("                               / \\  / _ \\| | | | / \\|_   _|_ _/ ___|\n");
        printf("                              / _ \\| | | | | | |/ _ \\ | |  | | |    \n");
        printf("                             / ___ \\ |_| | |_| / ___ \\| |  | | |___ \n");
        printf("                            /_/   \\_\\__\\_\\\\___/_/   \\_\\_| |___\\____|\n");
		break;

	case ALIEN_CRAWLER:
        printf("                         ____ ____      ___        ___     _____ ____  \n");
        printf("                        / ___|  _ \\    / \\ \\      / / |   | ____|  _ \\ \n");
        printf("                       | |   | |_) |  / _ \\ \\ /\\ / /| |   |  _| | |_) |\n");
        printf("                       | |___|  _ <  / ___ \\ V  V / | |___| |___|  _ < \n");
        printf("                        \\____|_| \\_\\/_/   \\_\\_/\\_/  |_____|_____|_| \\_\\\n");
		break;

	case ALIEN_GLOWING:
        printf("                          ____ _     _____        _____ _   _  ____ \n");
        printf("                         / ___| |   / _ \\ \\      / /_ _| \\ | |/ ___|\n");
        printf("                        | |  _| |  | | | \\ \\ /\\ / / | ||  \\| | |  _ \n");
        printf("                        | |_| | |__| |_| |\\ V  V /  | || |\\  | |_| |\n");
        printf("                         \\____|_____\\___/  \\_/\\_/  |___|_| \\_|\\____|\n");
		break;

	case ALIEN_CAMOUFLAGED:
        printf("              ____    _    __  __  ___  _   _ _____ _        _    ____ _____ ____  \n");
        printf("             / ___|  / \\  |  \\/  |/ _ \\| | | |  ___| |      / \\  / ___| ____|  _ \\ \n");
        printf("            | |     / _ \\ | |\\/| | | | | | | | |_  | |     / _ \\| |  _|  _| | | | |\n");
        printf("            | |___ / ___ \\| |  | | |_| | |_| |  _| | |___ / ___ \\ |_| | |___| |_| |\n");
        printf("             \\____/_/   \\_\\_|  |_|\\___/ \\___/|_|   |_____/_/   \\_\\____|_____|____/ \n");
		break;

	case ALIEN_ROCKY:
        printf("                                 ____   ___   ____ _  ____   __\n");
        printf("                                |  _ \\ / _ \\ / ___| |/ /\\ \\ / /\n");
        printf("                                | |_) | | | | |   | ' /  \\ V / \n");
        printf("                                |  _ <| |_| | |___| . \\   | |  \n");
        printf("                                |_| \\_\\\\___/ \\____|_|\\_\\  |_|  \n");
		break;

	case ALIEN_GAS_BASED:
        printf("                      ____    _    ____    ____    _    ____  _____ ____  \n");
        printf("                     / ___|  / \\  / ___|  | __ )  / \\  / ___|| ____|  _ \\ \n");
        printf("                    | |  _  / _ \\ \\___ \\  |  _ \\ / _ \\ \\___ \\|  _| | | | |\n");
        printf("                    | |_| |/ ___ \\ ___) | | |_) / ___ \\ ___) | |___| |_| |\n");
        printf("                     \\____/_/   \\_\\____/  |____/_/   \\_\\____/|_____|____/ \n");
		break;
    }
}