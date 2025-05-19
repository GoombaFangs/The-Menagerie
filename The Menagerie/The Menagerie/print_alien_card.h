#ifndef PRINT_ALIEN_CARD_H
#define PRINT_ALIEN_CARD_H

#include <stdio.h>
#include "alien_visuals.h"

int on_card_start(const alien* alien, int index);
int card1(const alien* alien, int index);
int card2(const alien* alien, int index);
int card3(const alien* alien, int index);
int card4(const alien* alien, int index);
void card1_details(const alien* alien, int index);
void card2_details(const alien* alien, int index);
void card3_details(const alien* alien, int index);
void card4_details(const alien* alien, int index);

#endif 
