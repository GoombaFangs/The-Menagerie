#ifndef ALIEN_STRUCT_H
#define ALIEN_STRUCT_H

typedef enum {
    ALIEN_FLYING,
    ALIEN_AQUATIC,
    ALIEN_CRAWLER,
    ALIEN_GLOWING,
    ALIEN_CAMOUFLAGED,
    ALIEN_ROCKY,
    ALIEN_GAS_BASED,
    ALIEN_TYPE_COUNT
} AlienType;

typedef struct
{
    char species[20];
    char sex; //'M' or 'F'
    int age;
    char size[20];
    char diet[20];
    char nickname[20];
    int art_variant;

    AlienType type;
} Alien;

#endif
