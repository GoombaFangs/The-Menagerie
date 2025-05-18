#include "Flying.h"

void print_flying(int variant)
{
    switch (variant)
    {
    case 0:
        printf(
            "     __|__\n"
            " --=( o o )=-\n"
            "     \\_v_/\n"
            "      / \\\n"
        );
        break;

    case 1:
        printf(
            "     __|__\n"
            " --=( o o )=--\n"
            "     \\___/\n"
            "      / \\\n"
        );
        break;

    case 2:
        printf(
            "     _____\n"
            "    /     \\\n"
            "   |  o o  |\n"
            "    \\__^__/\n"
            "     / | \\\n"
            "    *  |  *\n"
        );
        break;

    case 3:
        printf(
            "     \\ | /\n"
            "     (o_o)\n"
            "    <(   )>\n"
            "     /   \\\n"
        );
        break;

	case 4:
        printf(
            "       __\n"
            "  ====( o )>\n"
            "       \\\n"
            "        \\\n"
        );
		break;

	case 5:
        printf(
            "        __\n"
            "     __( o)>\n"
            "    /  (___)\n"
            "     \\  \\\n"
            "      \\_/\n"
        );
		break;

	case 6:
        printf(
            "     .-''''-.\n"
            "    / -   -  \\\n"
            "   |  .-. .-. |\n"
            "   |  \\o| |o/ |\n"
            "    \\     ^   /\n"
            "     '.  (_) .'\n"
            "       '-.-'\n"
            "     ~~~~~~~~~\n"
        );
		break;

	case 7:
        printf(
            "     .==-.                   .-==.\n"
            "    \\()8`-._  `.   .'  _.-'8()/\n"
            "    (88\"   ::.  \\./  .::   \"88)\n"
            "     \\_.'`-::::.(#).::::-'`._/\n"
            "       `._... .q(_)p. ..._.'\n"
            "         \"\"-..-'|=|`-..-\"\"\n"
            "               || |\n"
            "              (_._)\n"
        );
		break;

	case 8:
        printf(
            "     .--.\n"
            "    /    \\\n"
            "   |  ()  |\n"
            "   |  ||  |\n"
            "    \\_||_/\n"
            "     (__) \n"
            "     /  \\\n"
        );
		break;

	case 9:
        printf(
            "     \\  ^__^  /\n"
            "      \\(oo)  /\n"
            "        (__)\\\n"
            "       //  \\\\\n"
            "      ||    ||\n"
        );
		break;

    }
}
