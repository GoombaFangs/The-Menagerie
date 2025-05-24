#ifndef ZOO_H
#define ZOO_H

#include <stdlib.h>
#include <stdio.h>

#include "alien_folder.h"
#include "visuals_folder.h"

void add_alien_to_zoo(Alien alien);
int display_zoo();
void print_zoo_aliens(Alien* aliens, int count, int selected, int visible_count);

int get_zoo_count(void);
void zoo_setter(Alien* new_zoo, int count, int capacity);
int* get_zoo_count_ptr(void);
int* get_zoo_capacity_ptr(void);
Alien* get_zoo(void);
int get_zoo_capacity(void);

void remove_alien_from_zoo(int index);
int zoo_remove_alien_menu(Alien* aliens, int count, int selected);

#endif

