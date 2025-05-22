#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>

#include "input_keyboard.h"
#include "menu_option_data_base.h"
#include "alien_folder.h"
#include "visuals_folder.h"
#include "planet_folder.h"

Alien alien_selection_screen(char* planet_terrain ,int count);
Planet map_screen();
int main_menu_screen();
int story_screen(Planet planet);
void app_start();

#endif