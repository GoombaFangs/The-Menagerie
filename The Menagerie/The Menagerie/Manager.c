#include "manager.h"

void menu()
{
    srand(time(NULL));

    int alien_count = 1;
    Alien* aliens = generate_aliens(alien_count);

    if (aliens == NULL) {
        printf("Failed to generate aliens.\n");
        return;
    }

    for (int i = 0; i < alien_count; i++) {
        printf("Alien %d:\n", i + 1);
        printf("  Species: %s\n", aliens[i].species);
        printf("  Sex: %c\n", aliens[i].sex);
        printf("  Age: %d\n", aliens[i].age);
        printf("  Size: %s\n", aliens[i].size);
        printf("  Diet: %s\n", aliens[i].diet);
        printf("\n");
    }

    free(aliens);
}

void app_start()
{
   menu();
}