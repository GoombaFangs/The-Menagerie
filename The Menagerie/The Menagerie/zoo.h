#ifndef ZOO_H
#define ZOO_H

#include <stdlib.h>
#include <stdio.h>

#include "alien_struct.h"
#include "manager.h"

void add_alien_to_zoo(Alien alien);
int display_zoo();
void print_zoo_aliens(Alien* aliens, int count, int selected, int visible_count);
void save_zoo_to_file(const char* filename);
void load_zoo_from_file(const char* filename);
void remove_alien_from_zoo(int index);
void print_zoo_menu_options(int selected, const char* menu_list[], int amount);
int zoo_remove_alien_menu(Alien* aliens, int count, int selected);
void print_alien_visual_and_info(Alien* aliens, int index);


#endif

