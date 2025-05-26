#include "gas_based.h"

void print_gas_based(int variant)
{
    switch (variant)
    {
	case 0:
        printf(
            "                     ~  ~  ~\n"
            "                    (      )\n"
            "                     ~~~~\n"
            "                    (~~~~~~)\n"
        );
		break;

	case 1:
        printf(
            "                      ~~~~~~\n"
            "                    ~  o o  ~\n"
            "                   ~   (_)   ~\n"
            "                    ~   ^   ~\n"
            "                      ~~~~~~\n"
        );
		break;

	case 2:
        printf(
            "                     .-~~~~-.\n"
            "                    (  o  o  )\n"
            "                    (   o    )\n"
            "                     \\______/ \n"
            "                      ~~~~~~~~\n"
        );
		break;

	case 3:
        printf(
            "                      (     )\n"
            "                    (  o_o  )\n"
            "                   (   (_)   )\n"
            "                    (  ~~~  )\n"
            "                      (___)\n"
        );
		break;

	case 4:
        printf(
            "                    ~    .--.    ~\n"
            "                  ~     ( o_o )    ~\n"
            "                    ~    \\_/    ~\n"
            "                       ~~~~~~~~\n"
        );
		break;

	case 5:
        printf(
            "                      .-''''-.\n"
            "                     /  o  o  \\\n"
            "                    |    w     |\n"
            "                     \\__===__/ \n"
            "                      ~~~~~~~~\n"
        );
		break;

	case 6:
        printf(
            "                      *   *   *\n"
            "                    *   ( o )   *\n"
            "                   *    / ^ \\    *\n"
            "                    *   \\___/   *\n"
            "                      *   *   *\n"
        );
		break;

	case 7:
        printf(
            "                      .-.\n"
            "                    ( o o )\n"
            "                   (   x   )\n"
            "                    \\     /\n"
            "                     `~~~`\n"
            "                      / \\\n"
            "                     ~   ~\n"
        );
		break;

	case 8:
        printf(
            "                     ~~~~~~~~\n"
            "                    ~  o_o  ~\n"
            "                   ~   ^_^   ~\n"
            "                    ~~~~~~~~\n"
            "                      ~~~~\n"
        );
		break;

	case 9:
        printf(
            "                      ~~~~~~\n"
            "                     (  o  )\n"
            "                     \\_v_/~~~\n"
            "                      ~~~~\n"
            "                     ~   ~\n"
        );
		break;
    }
}