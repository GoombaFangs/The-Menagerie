#ifndef PLANET_MANAGER_H
#define PLANET_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "planet_folder.h"

Planet* generate_planet(int count);
char* travel_to_planet(char* planet_selected);

#endif