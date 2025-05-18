#include "AlienVisuals.h"


void print_alien_art(const Alien* alien, int index)
{
    printf(" Alien %d \n", index + 1);
    print_species_art(alien->species);
    printf("species: %s\n\n", alien->species);
}

void print_species_art(const char* species) 
{
    if (strcmp(species, "Flying") == 0) 
    {
        int variant = rand() % 10;
        print_flying(variant);
           
    }
    else if (strcmp(species, "Aquatic") == 0) {
        printf(
            "     ~~~~~~\n"
            "   ~ ( o ) ~\n"
            "  ~  \\___/  ~\n"
            "     ~~~~~~\n"
        );
    }
    else if (strcmp(species, "Crawler") == 0) {
        printf(
            "   __     __\n"
            "  /o \\~~~/ o\\\n"
            " (    o o    )\n"
            "  \\__/ ^ \\__/\n"
        );
    }
    else if (strcmp(species, "Quadruped") == 0) {
        printf(
            "   /\\___/\\\n"
            "  ( o   o )\n"
            "  (  =^=  )\n"
            "  (        )\n"
            "  (         )\n"
            "  (          ))))))))\n"
        );
    }
    else if (strcmp(species, "Glowing") == 0) {
        printf(
            "   .:: GLOWING ::.\n"
            "   *     (o_o)     *\n"
            "    *    /|||\\   *\n"
            "      *   ***   *\n"
        );
    }
    else if (strcmp(species, "Camouflaged") == 0) {
        printf(
            "   ~~~~ ~~~ ~~~~~~\n"
            "  (  o   o  )  ~~~\n"
            "  (   -^-   )  ~~~\n"
            "   \\_______/   ~~~\n"
        );
    }
    else if (strcmp(species, "Rocky") == 0) {
        printf(
            "   [#####]\n"
            "  [#######]\n"
            "   [#####]\n"
            "    [###]\n"
        );
    }
    else if (strcmp(species, "Gas-Based") == 0) {
        printf(
            "    ~  ~  ~\n"
            "   (      )\n"
            "    ~~~~\n"
            "   (~~~~~~)\n"
        );
    }
    else {
        printf(
            "    .-''''-.\n"
            "   /        \\\n"
            "  |  UNKNOWN |\n"
            "   \\________/\n"
        );
    }
}

void print_alien_card(const Alien* alien, int index) 
{
    printf("+--------- Alien %d ---------+\n", index + 1);
    printf("| Species  : %-15s |\n", alien->species);
    printf("| Sex      : %-15c |\n", alien->sex);
    printf("| Age      : %-15d |\n", alien->age);
    printf("| Size     : %-15s |\n", alien->size);
    printf("| Diet     : %-15s |\n", alien->diet);
    printf("| Nickname : %-15s |\n", alien->nickname[0] ? alien->nickname : "(none)");
    printf("+----------------------------+\n\n");
}