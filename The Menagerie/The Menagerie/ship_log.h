#ifndef SHIP_LOG_H
#define SHIP_LOG_H

#include "alien_folder.h"
#include "planet_folder.h"

void planet_log(const PlanetLog* planet);
void alien_log(const Zoo* zoo);
int reset_ship_log(Zoo* zoo, PlanetLog* planet_log);

#endif 