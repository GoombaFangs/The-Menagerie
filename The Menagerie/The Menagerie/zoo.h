#ifndef ZOO_H
#define ZOO_H

#include <stdlib.h>
#include <stdio.h>

#include "alien_folder.h"
#include "visuals_folder.h"

void add_alien_to_zoo(Alien alien);
int display_zoo();
void print_zoo_aliens(Alien* aliens, int count, int selected, int visible_count);
void save_zoo_to_file(const char* filename);
void load_zoo_from_file(const char* filename);

#endif

