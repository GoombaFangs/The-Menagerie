
#include "Visuals.h"

void print_alien(const Alien* alien, int index) {
    printf("+--------- Alien %d ---------+\n", index + 1);
    printf("| Species  : %-15s |\n", alien->species);
    printf("| Sex      : %-15c |\n", alien->sex);
    printf("| Age      : %-15d |\n", alien->age);
    printf("| Size     : %-15s |\n", alien->size);
    printf("| Diet     : %-15s |\n", alien->diet);
    printf("| Nickname : %-15s |\n", alien->nickname[0] ? alien->nickname : "(none)");
    printf("+----------------------------+\n\n");
}