#ifndef ALIENVISUALS_H
#define ALIENVISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Alien.h"
#include "AlienDataBase.h"
#include "Flying.h"
#include "Aquatic.h"

void print_alien_art(const Alien* alien, int index);
void print_species_art(const char* species);
void print_alien_card(const Alien* alien, int index);

#endif