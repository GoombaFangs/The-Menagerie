#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>

#include "input_keyboard.h"
#include "alien.h"
#include "visuals.h"

void get_aliens(alien* aliens ,int count);
int menu();
void app_start();

#endif