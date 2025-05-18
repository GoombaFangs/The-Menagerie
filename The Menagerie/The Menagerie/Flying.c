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

    }
}
