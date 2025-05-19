#ifndef PRINT_ALIEN_CARD_H
#define PRINT_ALIEN_CARD_H

#include <stdio.h>
#include "alien_visuals.h"

int on_card_start(const Alien* alien, int index);
int card1(const Alien* alien, int index);
int card2(const Alien* alien, int index);
int card3(const Alien* alien, int index);
int card4(const Alien* alien, int index);
void card1_details(const Alien* alien, int index);
void card2_details(const Alien* alien, int index);
void card3_details(const Alien* alien, int index);
void card4_details(const Alien* alien, int index);

#endif 
