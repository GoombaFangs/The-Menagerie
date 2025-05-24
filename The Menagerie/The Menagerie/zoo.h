#ifndef ZOO_H
#define ZOO_H

#include "alien_folder.h"
#include "visuals_folder.h"

void add_alien_to_zoo(Alien alien);
int display_zoo();
void print_zoo_aliens(Alien* aliens, int count, int selected, int visible_count);
void save_zoo_to_file(const char* filename);
void load_zoo_from_file(const char* filename);


//save stuff start
int get_zoo_count(void);
void zoo_setter(Alien* new_zoo, int count, int capacity);
int* get_zoo_count_ptr(void);
int* get_zoo_capacity_ptr(void);
Alien* get_zoo(void);
int get_zoo_capacity(void);
//save stuff end



#endif

