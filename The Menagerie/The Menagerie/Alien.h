#ifndef ALIEN_H
#define ALIEN_H

#include "alien_data_base.h"
#include "alien_manager.h"
#include "alien_visuals.h"

typedef struct
{
    char species[20];
    char sex; //'M' or 'F'
    int age;
    char size[20];
    char diet[20];
    char nickname[20];
} Alien;

#endif
