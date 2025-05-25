#ifndef ALIEN_ZOO_H
#define ALIEN_ZOO_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "alien_folder.h"
#include "visuals_folder.h"


int add_alien_to_zoo(Zoo* zoo, Alien alien);
void print_zoo_aliens(Alien* aliens, int count, int selected, int visible_count);
bool find_alien_in_zoo(const Zoo* zoo, AlienType type, int variant, Alien* result);
void free_zoo(Zoo* zoo);

#endif