#ifndef ALIEN_STRUCT_H
#define ALIEN_STRUCT_H

typedef struct
{
    char species[20];
    char sex; //'M' or 'F'
    int age;
    char size[20];
    char diet[20];
    char nickname[20];
    int art_variant;
} Alien;

#endif
