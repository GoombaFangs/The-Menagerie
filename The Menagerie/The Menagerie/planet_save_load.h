#ifndef PLANET_SAVE_LOAD_H
#define PLANET_SAVE_LOAD_H

#include "save_load_data.h"
#include "planet_folder.h"

void save_planet_to_file(const PlanetLog* log);
void load_planet_from_file(PlanetLog* log);
void free_planet(PlanetLog* log);

#endif 