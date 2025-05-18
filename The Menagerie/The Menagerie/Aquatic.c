#include "aquatic.h"

void print_aquatic(int variant)
{
    switch (variant)
    {
	case 0:
        printf(
            "     ~~~~~~\n"
            "   ~ ( o ) ~\n"
            "  ~  \\___/  ~\n"
            "     ~~~~~~\n"
        );
		break;

	case 1:
        printf(
            "     .-\"\"\"-.\n"
            "    / .===. \\\n"
            "   ( ( o o ) )\n"
            "    \\  ^  /\n"
            "     |||||\n"
            "     |||||\n"
            "     ' ' '\n"
        );
		break;

	case 2:
        printf(
            "     ><(((º>\n"
        );
		break;

	case 3:
        printf(
            "     .-.\n"
            "    (   ).\n"
            "   (___(__)\n"
            "    /  |  \\\n"
            "   '   |   '\n"
            "       |\n"
            "      ( )\n"
        );
		break;

	case 4:
        printf(
            "     ______\n"
            "  .-'      `-.\n"
            " /  o      o  \\\n"
            "|    ______    |\n"
            "\\   `------'  /\n"
            " `-._______.-'\n"
        );
		break;

	case 5:
		printf(
			"     ~~~~~~\n"
			"   ~ ( o ) ~\n"
			"  ~  \\___/  ~\n"
			"     ~~~~~~\n"
		);
		break;

	case 6:
        printf(
            "        ________\n"
            "  ____/        \\____\n"
            " <____    (o)     ___>\n"
            "      \\__________/\n"
            "       |  ||  |\n"
        );
		break;

	case 7:
        printf(
            "     .--._.--.\n"
            "    (  o   o  )\n"
            "     `-.\\_/.-'\n"
            "      /     \\\n"
            "     (       )\n"
            "      \\__ __/\n"
        );
		break;

	case 8:
        printf(
            "     .--.\n"
            "  __/ o o \\__\n"
            " /__   ^   __\\\n"
            "    |_____|\n"
            "    \\_____/\n"
        );
		break;

	case 9:
        printf(
            "      __><__\n"
            "     /      \\\n"
            "   <(        )>\n"
            "     \\______/ \n"
            "       \\  / \n"
            "        \\/\n"
        );
		break;

    }
}