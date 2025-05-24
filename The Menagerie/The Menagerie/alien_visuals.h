#ifndef ALIEN_VISUALS_H
#define ALIEN_VISUALS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "alien_folder.h"

void print_alien_art(const Alien* alien, int index);
void print_species_art(const char* type, int variant);
void alien_card(Alien* aliens, int index);
void zoo_alien_card(Alien* aliens, int index);
void print_alien_options(Alien* aliens, int count, int selected, int visible_count);

#endif