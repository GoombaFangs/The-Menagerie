#include "glowing.h"

void print_glowing(int variant)
{
	switch (variant)
	{
	case 0:
		printf(
			"                    .:: GLOWING ::.\n"
			"                    *     (o_o)     *\n"
			"                     *    /|||\\   *\n"
			"                       *   ***   *\n"
		);
		break;

	case 1:
		printf(
			"                        .::::::.\n"
			"                      .::::::::::.\n"
			"                     ::::::::::::::\n"
			"                    ':::::  (o_o) :::::'\n"
			"                      `::::.|-|.::::'\n"
			"                        `::::::::'\n"
			"                          '::::'\n"
			"                            ||\n"
			"                          __||__\n"
			"                         '------'\n"
		);
		break;
	
	case 2:
		printf(
			"                      .::::::::.\n"
			"                    .::   ()   ::.\n"
			"                   ::     __     ::\n"
			"                    '::._______.::'\n"
			"                        '::::::'\n"
		);
		break;
	
	case 3:
		printf(
			"                      *     *     *\n"
			"                    *    ( o )    *\n"
			"                      *   /_\\   *\n"
			"                    *     '-'     *\n"
			"                      *         *\n"
		);	                  
		break;

	case 4:
		printf(
			"                      .:::::.\n"
			"                    .:::::::::.\n"
			"                   ::(o)::::(o)::\n"
			"                    '::  =  ::'\n"
			"                      ':::::'\n"
			"                        ||\n"
			"                       ~~~\n"
		);
		break;
	case 5:
		printf(
			"                      .--------.\n"
			"                    .'   ()     '.\n"
			"                   /     __      \\\n"
			"                  |     (__)     |\n"
			"                   \\    --      /\n"
			"                    '._      _.'\n"
			"                       `----'\n"
		);
		break;

	case 6:
		printf(
			"                     *   *   *\n"
			"                    *   (o)   *\n"
			"                   *   < ^ >   *\n"
			"                    *   '-'   *\n"
			"                     *     *\n"
		);
		break;

	case 7:
		printf(
			"                    .:: GLOWING ::.\n"
			"                        /\\\n"
			"                       /  \\\n"
			"                      | o  |\n"
			"                       \\  /\n"
			"                        \\/\n"
			"                        ||\n"
			"                       ==== \n"
		);
		break;

	case 8:
		printf(
			"                      ~~~~~~\n"
			"                    ~  ( o )  ~\n"
			"                   ~    /_\\    ~\n"
			"                    ~   '-'   ~\n"
			"                      ~~~~~~\n"
		);
		break;

	case 9:
		printf(
			"                      _______\n"
			"                    /  ( o ) \\\n"
			"                   |    ___  |\n"
			"                    \\_______/\n"
			"                      \\   /\n"
			"                       \\_/\n"
		);
		break;
	}
}