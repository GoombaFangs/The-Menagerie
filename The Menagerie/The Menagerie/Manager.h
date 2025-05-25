#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>

#include "input_keyboard.h"
#include "menu_option_data_base.h"
#include "alien_folder.h"
#include "visuals_folder.h"
#include "planet_folder.h"
#include "save_load_data.h"
#include "ship_log.h"

Alien* alien_selection_screen(char* planet_terrain ,int count , int* selected_alien_index, int generate_new);
Planet map_screen();
int main_menu_screen();
int story_screen(Planet planet);
void new_alien_screen(Planet planet, int got_alien);
int ship_log_screen(const Zoo* zoo);
int explore_planet(Zoo* zoo);
void app_start();

#endif