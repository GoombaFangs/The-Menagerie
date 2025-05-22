#include "loading_screen.h"

void print_ship()
{
    printf("               __________________                                \n");
    printf("              /==\\______________\\                                \n");
    printf("             |                     >_________________________________\n");
    printf("    ---------|    ___     ___     ___     ___     ___     ___        \\\n");
    printf("    \\        |   |___|   |___|   |___|   |___|   |___|   |___|         >____________\n");
    printf("    /         \\__/ooo\\___/ooo\\___/ooo\\___/ooo\\___/ooo\\___/ooo\\_________/            \\\n");
    printf("   |________     |===|   |===|   |===|   |===|   |===|   |===|                       |\n");
    printf("           \\_____________________                                   __________________/\n");
    printf("                     /          /                                  /          \n");
    printf("                    /__________/          _______________________/          \n");
    printf("                              /___________/          \n");

}

void print_planet()
{
    printf("             _________              \n");
    printf("         .-'           '.           \n");
    printf("       .'                '.        \n");
    printf("     .'                    '.        \n");
    printf("    /                        \\       \n");
    printf("   /                          \\      \n");
    printf("  |                           |     \n");
    printf("  |                           |     \n");
    printf("  |                           |     \n");
    printf("   \\                         /      \n");
    printf("    \\                       /       \n");
    printf("     '.                   .'        \n");
    printf("       '-.             .-'          \n");
    printf("          '-._______.-'             \n");
}

void print_ship_arrive_planet()
{
	double durtion = 0.2;
    hold_seconds(durtion);
    reset_console();
    printf("   ___        \\\n");
    printf("  |___|         >____________\n");
    printf("_/ooo\\_________/            \\\n");
    printf("  |===|                       |\n");
    printf("             __________________/\n");
    printf("              /          \n");
    printf("____________/          \n");
    printf("  \n");
    print_planet();
    hold_seconds(durtion);
    reset_console();
    printf("___     ___     ___        \\\n");
    printf("___|   |___|   |___|         >____________\n");
    printf("oo\\___/ooo\\___/ooo\\_________/            \\\n");
    printf("===|   |===|   |===|                       |\n");
    printf("                          __________________/\n");
    printf("                          /          \n");
    printf(" _______________________/          \n");
    printf("____/          \n");
    print_planet();
    hold_seconds(durtion);
    reset_console();
    printf("___________                                \n");
    printf("__________\\                                \n");
    printf("             >_________________________________\n");
    printf("    ___     ___     ___     ___     ___        \\\n");
    printf("   |___|   |___|   |___|   |___|   |___|         >____________\n");
    printf("___/ooo\\___/ooo\\___/ooo\\___/ooo\\___/ooo\\_________/            \\\n");
    printf("   |===|   |===|   |===|   |===|   |===|                       |\n");
    printf("___________                                   __________________/\n");
    printf("/          /                                  /          \n");
    printf("__________/          _______________________/          \n");
    printf("         /___________/          \n");
    print_planet();
    hold_seconds(durtion);
    reset_console();
    printf("     __________________                                \n");
    printf("    /==\\______________\\                                \n");
    printf("   |                     >_________________________________\n");
    printf("---|    ___     ___     ___     ___     ___     ___        \\\n");
    printf("   |   |___|   |___|   |___|   |___|   |___|   |___|         >____________\n");
    printf("    \\__/ooo\\___/ooo\\___/ooo\\___/ooo\\___/ooo\\___/ooo\\_________/            \\\n");
    printf("__     |===|   |===|   |===|   |===|   |===|   |===|                       |\n");
    printf(" \\_____________________                                   __________________/\n");
    printf("           /          /                                  /          \n");
    printf("          /__________/          _______________________/          \n");
    printf("                    /___________/          \n");
    print_planet();
    hold_seconds(durtion);
    reset_console();
    print_ship();
    print_planet();
	hold_seconds(1);
}
	