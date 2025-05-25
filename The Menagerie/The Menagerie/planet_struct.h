#ifndef PLANET_STRUCT_H
#define PLANET_STRUCT_H

#include "alien_struct.h"

typedef struct
{
	char name[20];
    double distance;
    char terrain[20];
} Planet;

typedef struct
{
    Planet planet;
    Alien alien;
} PlanetVisit;

#endif