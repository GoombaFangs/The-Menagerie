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

void print_planet(char* planet_terrain)
{
    if (strcmp(planet_terrain, "ocean") == 0)
    {
        printf("             _________              \n");
        printf("         .-'           '.           \n");
        printf("       .'    ~           '.        \n");
        printf("     .'              ~     '.        \n");
        printf("    /     ~                  \\       \n");
        printf("   /           ~          ~   \\      \n");
        printf("  |   ~             ~         |     \n");
        printf("  |          ~          ~     |     \n");
        printf("  |              ~            |     \n");
        printf("   \\   ~                     /      \n");
        printf("    \\                ~      /       \n");
        printf("     '.     ~             .'        \n");
        printf("       '-.        ~    .-'          \n");
        printf("          '-._______.-'             \n");
    }
    else if (strcmp(planet_terrain, "desert") == 0)
    {
        printf("             _________              \n");
        printf("         .-'           '.           \n");
        printf("       .'      ===       '.        \n");
        printf("     .'                    '.        \n");
        printf("    /        ==    ====      \\       \n");
        printf("   / ========                 \\      \n");
        printf("  |             ====== ==     |     \n");
        printf("  |    ===              ==    |     \n");
        printf("  |          ====             |     \n");
        printf("   \\             =====  ==   /      \n");
        printf("    \\        ==             /       \n");
        printf("     '.   ==       =====  .'        \n");
        printf("       '-.  ====       .-'          \n");
        printf("          '-._______.-'             \n");
    }
    else if (strcmp(planet_terrain, "forest") == 0) 
    {
        printf("             _________              \n");
        printf("         .-'           '.           \n");
        printf("       .'    ^    ^      '.        \n");
        printf("     .'              ^     '.        \n");
        printf("    /     ^      ^       ^   \\       \n");
        printf("   /   ^     ^      ^         \\      \n");
        printf("  |                      ^    |     \n");
        printf("  |   ^     ^       ^      ^  |     \n");
        printf("  |             ^       ^     |     \n");
        printf("   \\    ^     ^     ^     ^  /      \n");
        printf("    \\ ^    ^     ^     ^    /       \n");
        printf("     '.   ^     ^     ^   .'        \n");
        printf("       '-.  ^     ^    .-'          \n");
        printf("          '-._______.-'             \n");
    }
    else if (strcmp(planet_terrain, "swamp") == 0)
    {
        printf("             _________              \n");
        printf("         .-'           '.           \n");
        printf("       .'    ^           '.        \n");
        printf("     .'              ^     '.        \n");
        printf("    /     ^      ^       ^   \\       \n");
        printf("   /   ^     ^      ^        /\\      \n");
        printf("  |                    _____/ |     \n");
        printf("  |\\ ^     ^       ^ /       |     \n");
        printf("  |  \\______________/     ~  |     \n");
        printf("   \\                         /      \n");
        printf("    \\  ~      ~     ~       /       \n");
        printf("     '.                   .'        \n");
        printf("       '-.    ~     ~  .-'          \n");
        printf("          '-._______.-'             \n");
    }
    else if (strcmp(planet_terrain, "mountain") == 0)
    {
        printf("             _________              \n");
        printf("         .-'           '.           \n");
        printf("       .'         /^\\  '.        \n");
        printf("     .'   /^\\            '.        \n");
        printf("    /                        \\       \n");
        printf("   /              /^\\        \\      \n");
        printf("  |                           |     \n");
        printf("  |       /^\\                |     \n");
        printf("  |                     /^\\  |     \n");
        printf("   \\                         /      \n");
        printf("    \\                       /       \n");
        printf("     '.     /^\\          .'        \n");
        printf("       '-.             .-'          \n");
        printf("          '-._______.-'             \n");
    }
    else if (strcmp(planet_terrain, "volcanic") == 0)
    {
        printf("             _________              \n");
        printf("         .-'  @        '.           \n");
        printf("       .'         /^\\  '.        \n");
        printf("     .'   /^\\            '.        \n");
        printf("    /   @               @    \\       \n");
        printf("   /   @@@@       /^\\  @@    \\      \n");
        printf("  |   @@        @        @@   |     \n");
        printf("  |       /^\\ @@@@           |     \n");
        printf("  |              @      /^\\  |     \n");
        printf("   \\     @@@        @        /      \n");
        printf("    \\   @         @@@@@     /       \n");
        printf("     '.     /^\\    @@    .'        \n");
        printf("       '-.             .-'          \n");
        printf("          '-._______.-'             \n");
    }
    else if (strcmp(planet_terrain, "icy") == 0)
    {
        printf("             _________              \n");
        printf("         .-'           '.           \n");
        printf("       .'                '.        \n");
        printf("     .'      *       *     '.        \n");
        printf("    /    *                   \\       \n");
        printf("   /                *    **   \\      \n");
        printf("  |             *             |     \n");
        printf("  |      *               *    |     \n");
        printf("  |               *           |     \n");
        printf("   \\ *    *          ***     /      \n");
        printf("    \\                       /       \n");
        printf("     '.       *           .'        \n");
        printf("       '-.        *    .-'          \n");
        printf("          '-._______.-'             \n");
    }
    else if (strcmp(planet_terrain, "gas") == 0)
    {
        printf("             _________              \n");
        printf("         .-'           '.           \n");
        printf("       .' \\   ;      ;  '.        \n");
        printf("     .'    |     ;         '.        \n");
        printf("    /   ;  |   ;         ;   \\       \n");
        printf("   /      /           ;       \\      \n");
        printf("  |  ;   /       ; ;    ; ____|     \n");
        printf("  |_____/   ;             \\  |     \n");
        printf("  |                      ; \\_|     \n");
        printf("   \\    ;     ;       ;      /      \n");
        printf("    \\                       /       \n");
        printf("     '.    ;    ;    ;    .'        \n");
        printf("       '-.             .-'          \n");
        printf("          '-._______.-'             \n");
        }
    else if (strcmp(planet_terrain, "urban ruins") == 0)
    {
        printf("             _________              \n");
        printf("         .-'    __/    '.           \n");
        printf("       .'      /         '.        \n");
        printf("     .'_______/            '.        \n");
        printf("    /            |||         \\       \n");
        printf("   /                          \\      \n");
        printf("  |   |||             |||     |     \n");
        printf("  |                           |     \n");
        printf("  |       |||                 |     \n");
        printf("   \\              |||        /      \n");
        printf("    \\                       /       \n");
        printf("     '.     |||           .'        \n");
        printf("       '-.             .-'          \n");
        printf("          '-._______.-'             \n");
    }
    else if (strcmp(planet_terrain, "crystal plains") == 0)
    {
        printf("             _________              \n");
        printf("         .-'           '.           \n");
        printf("       .'       *>       '.        \n");
        printf("     .'   <*>              '.        \n");
        printf("    /                  <*>   \\       \n");
        printf("   /                          \\      \n");
        printf("  |               <*>         |     \n");
        printf("  |   <*>                     |     \n");
        printf("  |                    <*     |     \n");
        printf("   \\                         /      \n");
        printf("    \\     <*                /       \n");
        printf("     '.          <*>      .'        \n");
        printf("       '-.             .-'          \n");
        printf("          '-._______.-'             \n");
    }
    else
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

}
 
void print_ship_arrive_planet(char* planet_terrain)
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
    print_planet(planet_terrain);
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
    print_planet(planet_terrain);
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
    print_planet(planet_terrain);
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
    print_planet(planet_terrain);
    hold_seconds(durtion);
    reset_console();
    print_ship();
    print_planet(planet_terrain);
	hold_seconds(1);
}

void print_planet_menu(char* planet_terrain)
{
	print_ship();
	print_planet(planet_terrain);
	printf("                                                           %s planet\n\n", planet_terrain);
}

void print_space_windows()
{
    printf("     ____________           ____________________________________________           ____________\n");
    printf("    /          . \\         /                                            \\         /            \\\n");
    printf("   /   *          \\       /           *         *             .     *    \\       /          *   \\\n");
    printf("  |   .     *      |     |    *       .     .        .    *     .   .     |     |  *     .       |\n");
    printf("  |  *   .     .   |     |       .       *       *     .        *      .  |     |    .    *      |\n");
    printf("  |   .    *   .   |     |   .      .        .     .      *  .     *      |     |  .  *     .    |\n");
    printf("  |    *   .    *  |     |        *    .     .    *    .     .     .      |     |     *    .     |\n");
    printf("  |  .     . *     |     |  .   *     *    .   .    *      .     *     .  |     |   .     *      |\n");
    printf("  |    .    *      |     |     .      .     *     .     .    *     .      |     | .   *     .    |\n");
    printf("   \\    .      *  /       \\       .    *                *                /       \\         .    /\n");
    printf("    \\____________/         \\____________________________________________/         \\____________/\n");
	printf("                      ___ _                                                    ___                 \n");
    printf("      _______________________________________________________________________________________ \n");
    printf("     | [==     ] [====   ] [========] [==     ] [======  ]  [DOOR] [AIR] [CORE] [ENG] [SHLD] | \n");
    printf("     | ||| |||   ||||     ||||||||   ||| |||   |||||                        ^   ^     ^      | \n");
    printf("     | |_| |_|   |_|      |_____|    |_| |_|   |___|                       ( ) ( )   ( )     | \n");
    printf("     |_______________________________________________________________________________________| \n");
	printf("\n\n");
}

void stars()
{
	printf(" *       .                 *        *        *        .      *        *   .  *     .     \n");
	printf("   .               .              .    *              *   .  *          .     *    *   .  *      *   .  *\n");
	printf("       *              *              .   *                     .  *      .       *  *       .   *\n");
	printf("      *   .              .                      *     .  *                        .      *       \n");
	printf("         .  *       .               *    .            *       .         *             *     .       * \n");
	printf("       *       .                  .                *    .            *    .      *   .        *  \n");
	printf("         .      *   .        *        .   *            .    *        *        .   *     .    *\n");
    printf("          *       .                 .         *          *            .             .  *     .     \n");
    printf("     *   .      *                      *            *       .                  *         .        *  \n");
    printf("       *        .               .  *        *   .             .      *        *   .  *     .     \n");
    printf("         *         .                      .           .           *   .        *     .           *  \n");
    printf("     .      *         *        .   *          .  *    .      *   .        *                . \n");
	printf("\n\n");
}
	