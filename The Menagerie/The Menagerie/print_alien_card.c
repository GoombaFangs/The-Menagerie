#include "print_alien_card.h"

int on_card_start(const Alien* alien, int index)
{
	
	for (int i = 0; i < index; i++)
	{
		if (i == 0)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n\n\n\n\n", i + 1);
		}		
		print_alien_art(&alien[i], i);
		if(i == 0)
		{
			printf("+----------------------------+\n\n\n\n");
		}	
	}
	return 1;
}

int card1(const Alien* alien, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (i == 0)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n\n\n\n\n", i + 1);
		}
		print_alien_art(&alien[i], i);
		if (i == 0)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
	return 1;
}

int card2(const Alien* alien, int index)
{
	for (int i = 1; i < index; i++)
	{
		if (i == 1)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n\n\n\n\n", i + 1);
		}
		print_alien_art(&alien[i], i);
		if (i == 1)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
	return 2;
}

int card3(const Alien* alien, int index)
{
	for (int i = 2; i < index; i++)
	{
		if (i == 2)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n\n\n\n\n", i + 1);
		}
		print_alien_art(&alien[i], i);
		if (i == 2)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
	return 3;
}

int card4(const Alien* alien, int index)
{
	for (int i = 3; i < index; i++)
	{
		if (i == 3)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n\n\n\n\n", i + 1);
		}
		print_alien_art(&alien[i], i);
		if (i == 3)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
	return 4;
}

void card1_details(const Alien* alien, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (i == 0)
		{
			printf("+--------- Alien %d ---------+", i + 1);
			printf("       +----------------------------+\n");
			printf("                                    | Species  : %-15s |\n", alien[i].species);
			printf("                                    | Sex      : %-15c |\n", alien[i].sex);
			printf("                                    | Age      : %-15d |\n", alien[i].age);
			printf("                                    | Size     : %-15s |\n", alien[i].size);
			printf("                                    | Diet     : %-15s |\n", alien[i].diet);
			printf("                                    | Nickname : %-15s |\n", alien[i].nickname[0] ? alien->nickname : "(none)");
			printf("                                    +----------------------------+\n");
		}
		print_alien_art(&alien[i], i);
		if (i == 0)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
}

void card2_details(const Alien* alien, int index)
{
	for (int i = 1; i < index; i++)
	{
		if (i == 1)
		{
			printf("+--------- Alien %d ---------+", i + 1);
			printf("       +----------------------------+\n");
			printf("                                    | Species  : %-15s |\n", alien[i].species);
			printf("                                    | Sex      : %-15c |\n", alien[i].sex);
			printf("                                    | Age      : %-15d |\n", alien[i].age);
			printf("                                    | Size     : %-15s |\n", alien[i].size);
			printf("                                    | Diet     : %-15s |\n", alien[i].diet);
			printf("                                    | Nickname : %-15s |\n", alien[i].nickname[0] ? alien->nickname : "(none)");
			printf("                                    +----------------------------+\n");
		}
		print_alien_art(&alien[i], i);
		if (i == 1)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
}

void card3_details(const Alien* alien, int index)
{
	for (int i = 2; i < index; i++)
	{
		if (i == 2)
		{
			printf("+--------- Alien %d ---------+", i + 1);
			printf("       +----------------------------+\n");
			printf("                                    | Species  : %-15s |\n", alien[i].species);
			printf("                                    | Sex      : %-15c |\n", alien[i].sex);
			printf("                                    | Age      : %-15d |\n", alien[i].age);
			printf("                                    | Size     : %-15s |\n", alien[i].size);
			printf("                                    | Diet     : %-15s |\n", alien[i].diet);
			printf("                                    | Nickname : %-15s |\n", alien[i].nickname[0] ? alien->nickname : "(none)");
			printf("                                    +----------------------------+\n");
		}
		print_alien_art(&alien[i], i);
		if (i == 2)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
}

void card4_details(const Alien* alien, int index)
{
	for (int i = 3; i < index; i++)
	{
		if (i == 3)
		{
			printf("+--------- Alien %d ---------+", i + 1);
			printf("       +----------------------------+\n");
			printf("                                    | Species  : %-15s |\n", alien[i].species);
			printf("                                    | Sex      : %-15c |\n", alien[i].sex);
			printf("                                    | Age      : %-15d |\n", alien[i].age);
			printf("                                    | Size     : %-15s |\n", alien[i].size);
			printf("                                    | Diet     : %-15s |\n", alien[i].diet);
			printf("                                    | Nickname : %-15s |\n", alien[i].nickname[0] ? alien->nickname : "(none)");
			printf("                                    +----------------------------+\n");
		}
		print_alien_art(&alien[i], i);
		if (i == 3)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
}
