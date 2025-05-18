#ifndef ALIENVISUALS_H
#define ALIENVISUALS_H

#include <stdio.h>
#include "Alien.h"
#include "AlienDataBase.h"
#include "Flying.h"

void print_alien_art(const Alien* alien, int index);
void print_species_art(const char* species);
void print_alien_card(const Alien* alien, int index);

#endif