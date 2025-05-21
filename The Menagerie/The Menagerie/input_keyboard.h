#ifndef INPUT_KEYBOARD_H
#define INPUT_KEYBOARD_H

#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "visuals_folder.h"
#include "menu_option.h"
#include "alien_folder.h"

int input_menu(const char* menu_list[], int amount);

int input_aliens(Alien* aliens, int count);

void print_style_1(int selected, const char* menu_list[], int amount);
void print_style_2(Alien* aliens, int count, int selected);

#endif
