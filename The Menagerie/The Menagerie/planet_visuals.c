#include "planet_visuals.h"

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
        printf("       .'         /^\\   '.        \n");
        printf("     .'   /^\\             '.        \n");
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
        printf("       .'         /^\\   '.        \n");
        printf("     .'   /^\\             '.        \n");
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