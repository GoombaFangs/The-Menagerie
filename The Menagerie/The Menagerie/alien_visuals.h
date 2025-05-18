#ifndef ALIEN_VISUALS_H
#define ALIEN_VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "alien.h"
#include "alien_data_base.h"
#include "alien_species.h"

void print_alien_art(const Alien* alien, int index);
void print_species_art(const char* species);
void print_alien_card(const Alien* alien, int index);

#endif