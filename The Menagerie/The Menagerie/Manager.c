#include "manager.h"

void menu()
{
    srand((unsigned int)time(NULL));

    int num_aliens = 10;

    Alien* aliens = generate_aliens(num_aliens);

    for (int i = 0; i < num_aliens; i++) {
        print_alien_art_only(&aliens[i], i);
    }

   /* for (int i = 0; i < num_aliens; i++) {
        print_alien(&aliens[i], i);
    }*/
    free(aliens);
}

void app_start()
{
   menu();
}