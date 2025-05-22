#ifndef INPUT_KEYBOARD_H
#define INPUT_KEYBOARD_H

#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "visuals_folder.h"
#include "menu_option_data_base.h"
#include "alien_folder.h"
#include "manager.h"

void print_text_options(int selected, const char* menu_list[], int amount);
int input_text(const char* menu_list[], int amount, int console, char* planet_terrain);// console 1 to reset console 0 to not reset

void print_alien_options(Alien* aliens, int count, int selected, int visible_count);
int input_aliens(char* planet_terrain, Alien* aliens, int count);

#endif
