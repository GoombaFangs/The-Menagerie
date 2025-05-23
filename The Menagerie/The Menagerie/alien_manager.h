#ifndef ALIEN_MANAGER_H
#define ALIEN_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "alien_folder.h"
#include "visuals_folder.h"
#include "input_keyboard.h"

int get_alien_types_for_terrain(const char* terrain, AlienType* out_types);
const char* get_alien_type_name(AlienType type);
Alien add_nickname(Alien* alien, int selected_index, int* backspace);
Alien* generate_aliens(char* planet_terrain, int count);

#endif