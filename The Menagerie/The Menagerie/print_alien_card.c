#include "print_alien_card.h"

int on_card_start(const Alien* alien, int index)
{
	for (int i = 0; i < index; i++)
	{
		print_alien_art(&alien[i], i);
	}
	return 1;
}

int on_card1(const Alien* alien, int index)
{
	
	return 1;
}

int on_card2(const Alien* alien, int index)
{
	return 2;
}

int on_card3(const Alien* alien, int index)
{
	return 3;
}

int on_card4(const Alien* alien, int index)
{
	return 4;
}


