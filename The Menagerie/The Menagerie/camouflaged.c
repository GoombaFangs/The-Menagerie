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
	}
}