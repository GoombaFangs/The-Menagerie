#ifndef INPUT_KEYBOARD_H
#define INPUT_KEYBOARD_H

#include "visuals.h"
#include "menu_option.h"

void print_options_menu(int selected, const char* menu_list[], int amount);
int input(const char* menu_list[], int amount);

#endif 
