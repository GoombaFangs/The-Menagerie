#ifndef VISUALS_H
#define VISUALS_H

#include <stdio.h>
#include "Alien.h"
#include "AlienData.h"

void print_alien_art_only(const Alien* alien, int index);
void print_species_art(const char* species);
void print_flying_ascii_variant(int variant);
void print_alien(const Alien* alien, int index);

#endif