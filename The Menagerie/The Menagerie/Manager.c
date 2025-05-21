#include "manager.h"

#define NUM_ALIENS 5
#define NUM_PLANETS 8

Alien alien_selection_screen(char* planet_terrain , int count)
{
    Alien* aliens = generate_aliens(planet_terrain ,NUM_ALIENS);

    int selected = input_aliens(aliens, count);

    return aliens[selected];
}

char* map_screen()
{
    Planet* planets = generate_planet(NUM_PLANETS);

    const char** terrain_ptrs = malloc(NUM_PLANETS * sizeof(char*));
    if (!terrain_ptrs)
    {
        printf("Memory allocation failed!\n");
        free(planets);
        return -1;
    }

    for (int i = 0; i < NUM_PLANETS; i++)
    {
        terrain_ptrs[i] = planets[i].terrain;
    }

    int selected_planet = input_menu(terrain_ptrs, NUM_PLANETS);
	char* planet_terrain = travel_to_planet(planets[selected_planet].terrain);

    scroll_to_line(0);
    free(terrain_ptrs);
    free(planets);

    return planet_terrain;
}

int main_menu_screen()
{
    int selected = input_menu(main_menu_list, main_menu_num);
    return selected;
}

void app_start()
{
   srand((unsigned int)time(NULL));

   int running = 1;
   int do_next = main_menu_screen();
   Alien selected_alien = { 0 };

   while (running)
   {
       switch (do_next)
       {
	   case -1: // return to menu
           do_next = main_menu_screen();
		   break;

       case 0: // Explore Planet
       {
           char* planet_terrain = map_screen();
           printf("You have traveled to planet %s.\n", planet_terrain);
           selected_alien = alien_selection_screen(planet_terrain, NUM_ALIENS);
           do_next = -1;
           break;
       }

       case 1: //zoo
           do_next = -1;
		   // TODO: open zoo
           break;

       case 2: //inventory
           do_next = -1;
           // TODO: open inventory
           break;

       case 3: //exit
           running = 0;
           break;
	   case 4: //add alien to the zoo
           do_next = -1;
           // TODO: add alien to zoo
		   break;

       default:
           do_next = -1;
           break;
       }
   }
}