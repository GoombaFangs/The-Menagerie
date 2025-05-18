#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>

//alien
#include "alien.h"
#include "alien_visuals.h"
#include "alien_manager.h"
#include "alien_data_base.h"

//visuals
#include "visuals.h"
#include "print_menu.h"

void get_aliens(int count);
int menu();
void app_start();

#endif