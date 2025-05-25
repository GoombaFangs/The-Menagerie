#ifndef INPUT_KEYBOARD_H
#define INPUT_KEYBOARD_H

#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "visuals_folder.h"
#include "menu_option_data_base.h"
#include "alien_folder.h"


void print_text_options(int selected, const char* menu_list[], int amount, int console);
int input_text(const char* menu_list[], int amount, int console_style, char* planet_terrain);// console 0 to reset console
int input_zoo(Zoo* zoo);
int input_aliens(char* planet_terrain, Alien* aliens, int count);
int get_alpha_input(char* inputBuffer, int bufferSize);

#endif