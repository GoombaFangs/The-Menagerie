#include "print_alien_card.h"

int on_card_start(const Alien* alien, int index)
{
	
	for (int i = 0; i < index; i++)
	{
		if (i == 0)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n", i + 1);
		}		
		print_alien_art(&alien[i], i);
		if(i == 0)
		{
			printf("+----------------------------+\n\n\n\n");
		}	
	}
	return 1;
}

int on_card1(const Alien* alien, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (i == 0)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n", i + 1);
		}
		print_alien_art(&alien[i], i);
		if (i == 0)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
	return 1;
}

int on_card2(const Alien* alien, int index)
{
	for (int i = 1; i < index; i++)
	{
		if (i == 1)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n", i + 1);
		}
		print_alien_art(&alien[i], i);
		if (i == 1)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
	return 2;
}

int on_card3(const Alien* alien, int index)
{
	for (int i = 2; i < index; i++)
	{
		if (i == 2)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n", i + 1);
		}
		print_alien_art(&alien[i], i);
		if (i == 2)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
	return 3;
}

int on_card4(const Alien* alien, int index)
{
	for (int i = 3; i < index; i++)
	{
		if (i == 3)
		{
			printf("+--------- Alien %d ---------+\n\n\n\n", i + 1);
		}
		print_alien_art(&alien[i], i);
		if (i == 3)
		{
			printf("+----------------------------+\n\n\n\n");
		}
	}
	return 4;
}


