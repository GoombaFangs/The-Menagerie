#include "camouflaged.h"

void print_camouflaged(int variant)
{
	switch (variant)
	{
	case 0:
		printf(
			"   ~~~~ ~~~ ~~~~~~\n"
			"  (  o   o  )  ~~~\n"
			"  (   -^-   )  ~~~\n"
			"   \\_______/   ~~~\n"
		);
		break;
	case 1:
		printf(
			"   /\\___/\\\n"
			"  ( o   o )\n"
			"  (  =^=  )\n"
			"  (        )\n"
			"  (         )\n"
			"  (          ))))))))\n"
		);
		break;

	case 2:
		printf(
			"   (\\__/)\n"
			"   ( •.• )>\n"
			"  /|  |\\ \n"
			" //   \\\\\n"
		);
		break;

	case 3:
		printf(
			"     ,--./,-.\n"
			"    / #      \\\n"
			"   |          |\n"
			"    \\        /\n"
			"     `._,._.'\n"
			"     ( o o )\n"
			"      \\_^_/\n"
		);
		break;

	case 4:
		printf(
			"     /////\\\\\\\n"
			"    /// o o \\\\\n"
			"   |||   ^   |||\n"
			"    \\\\_____///\n"
			"     \\\\___//\n"
		);
		break;

	case 5:
		printf(
			"     /\\_/\\ \n"
			"    ( -.- )\n"
			"    >  ^  <\n"
			"     \\___/\n"
			"    //   \\\\\n"
		);
		break;

	case 6:
		printf(
			"     _______\n"
			"    /       \\\n"
			"   |  [:::]  |\n"
			"   |   0 0   |\n"
			"    \\___^___/\n"
		);
		break;

	case 7:
		printf(
			"     /\\___/\\\n"
			"    ( o   o )\n"
			"    (   ,   )\n"
			"     \\__^__/\n"
			"      || ||\n"
		);
		break;

	case 8:
		printf(
			"    /\\_____/\n"
			"   (  o   o  )\n"
			"   (    /    )\n"
			"   /  _____  \\\n"
			"  /_/     \\_\\\n"
		);
		break;

	case 9:
		printf(
			"    __       _\n"
			"  /    \\~~~/  \\\n"
			" |  o    o    |\n"
			" |     !      |\n"
			"  \\__________/\n"
			"    /      \\\n"
		);
		break;
	}
}