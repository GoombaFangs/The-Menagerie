#ifndef PLANET_MANAGER_H
#define PLANET_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "planet_folder.h"

void generate_random_name(char* name, int max_length);
Planet* generate_planet(int count);
Planet travel_to_planet(Planet planet_selected);

#endif