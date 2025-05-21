#include "manager.h"

#define NUM_ALIENS 4
#define NUM_PLANETS 10

int alien_selection_screen(alien* aliens, int count)
{

    int selected = input_aliens(aliens, count);
    return selected;//alien is selected
}

int map_screen()
{
    planet* planets = generate_planet(NUM_PLANETS);

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

    int selected = input_menu(terrain_ptrs, NUM_PLANETS);

    scroll_to_line(0);
    free(terrain_ptrs);
    free(planets);

    return selected;
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

   alien* aliens = generate_aliens(NUM_ALIENS);

   while (running)
   {
       switch (do_next)
       {
	   case -1: // return to menu
           do_next = main_menu_screen();
		   break;

       case 0: // Explore Planet
           map_screen();
           do_next = alien_selection_screen(aliens, NUM_ALIENS);
           break;

       case 1: //zoo
           do_next = main_menu_screen();
		   // TODO: open zoo
           break;

       case 2: //inventory
           do_next = main_menu_screen();
           // TODO: open inventory
           break;

       case 3: //exit
           running = 0;
           break;
	   case 4: //add alien to the zoo
           do_next = main_menu_screen();
           // TODO: add alien to zoo
		   break;

       default:
           do_next = main_menu_screen();
           break;
       }
   }

   free(aliens);
   
}