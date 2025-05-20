#ifndef INPUT_KEYBOARD_H
#define INPUT_KEYBOARD_H

#include "visuals.h"
#include "menu_option.h"

void print_style_1(int selected, const char* menu_list[], int amount);
int input(int style, const char* menu_list[], int amount);

#endif 
