#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>

#include "input_keyboard.h"
#include "menu_option_data_base.h"
#include "alien_folder.h"
#include "visuals_folder.h"
#include "planet_folder.h"
#include "zoo.h"
#include "save_load_data.h"

Alien* alien_selection_screen(char* planet_terrain ,int count , int* selected_alien_index, int generate_new);
Planet map_screen();
int main_menu_screen();
int story_screen(Planet planet);
void new_alien_screen(Planet planet, int got_alien);
int ship_log_screen();
void app_start();

#endif