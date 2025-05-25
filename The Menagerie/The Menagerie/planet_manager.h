#ifndef PLANET_MANAGER_H
#define PLANET_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "planet_folder.h"
#include "alien_folder.h"

void generate_random_name(char* name, int max_length);
Planet* generate_planet(int count);

extern PlanetVisit* visited_planets;
extern int num_visited_planets;
extern int visited_capacity;

void planet_log();
void add_planet_visit(Planet planet, Alien alien);

#endif