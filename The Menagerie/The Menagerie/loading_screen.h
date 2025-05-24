#ifndef LOADING_SCREEN_H
#define LOADING_SCREEN_H

#include "visuals_folder.h"
#include "planet_folder.h"

void title();
void print_ship();
void print_planet(char* planet_terrain);
void print_ship_leave_planet(char* planet_terrain, int got_alien);
void print_ship_arrive_planet(char* planet_terrain);
void print_planet_menu(char* planet_terrain);
void print_space_window();
void print_space_window_star_fal();
void print_space_window_anim();
void print_big_window();
void print_control_panel();
void print_screen_panel();
void print_captain_seat();
void print_ship_log();
void stars();

#endif 