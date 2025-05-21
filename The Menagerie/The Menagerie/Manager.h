#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>

#include "input_keyboard.h"
#include "menu_option.h"
#include "alien_folder.h"
#include "visuals_folder.h"
#include "planet_folder.h"

int alien_selection_screen(alien* aliens, int count);
int map_screen();
int main_menu_screen();
void app_start();

#endif