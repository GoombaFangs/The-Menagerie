#include "Crawler.h"

void print_crawler(int variant)
{
    switch (variant)
    {
	case 0:
        printf(
            "   __     __\n"
            "  /o \\~~~/ o\\\n"
            " (    o o    )\n"
            "  \\__/ ^ \\__/\n"
        );
		break;

	case 1:
        printf(
            "     __     __\n"
            "   |__|___|__|\n"
            "  /           \\\n"
            " (  o   o   o  )\n"
            "  \\___________/\n"
        );
		break;

	case 2:
        printf(
            "    .==.   .==.\n"
            "   ( oo ) ( oo )\n"
            "    \\__/   \\__/\n"
            "    /||\\   /||\\\n"
        );
		break;

	case 3:
        printf(
            "        ______\n"
            "     .-'      `-.\n"
            "   .'            `. \n"
            "  /  .--------.     \\\n"
            " :  /          \\     ;-___.--.\n"
            " | :            ;   |.'        `.\n"
            " :  \\          /   ; /      o   \\\n"
            "  \\  `--------'   /|            |\n"
            "   `.            .'    '.__.3-  /\n"
            "     `-.______.-'--------------'\n"
        );
		break;

	case 4:
        printf(
            "      @@@\n"
            "   @@@   @@@\n"
            "  @         @\n"
            "   @@@   @@@\n"
            "      @@@\n"
            "        \\\n"
            "         \\\n"
            "     .-''''-.\n"
            "    / o    o \\\n"
            "   |    ∆     |\n"
            "    \\  '--'  /\n"
            "     `------`\n"
        );
		break;

	case 5:
        printf(
            "        @@@@@@@\n"
            "     @@@       @@@\n"
            "   @@   .----.   @@\n"
            "   |   / o  o \\   |\n"
            "   |   \\_ ∆ _/   |\n"
            "   |    -----    |\n"
            "    \\___________/\n"
        );
		break;

	case 6:
        printf(
            "   @@@\n"
            "  @   @\n"
            "   @@@  o_o\n"
            "        /|\\\n"
        );
		break;

	case 7:
        printf(
            "    __\n"
            "  (o_o)--@\n"
        );
		break;

	case 8:
        printf(
            "    @@@@\n"
            "  @      @    \n"
            " @         @  ,\n"
            "  @  ___  @ //\n"
            "    \\___/__//()()  \n"
            "     (__________ ) \n"
        );
		break;
	case 9:
        printf(
            "     ______\n"
            "   /  o  o  \\\n"
            "  |    ∆     |\n"
            "   \\__===__/~~~\n"
            "        @@@@\n"
            "       @    @\n"
            "        @@@@\n"
        );
		break;
    }
}