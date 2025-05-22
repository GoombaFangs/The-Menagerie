#include "manager.h"

#define NUM_ALIENS 15
#define NUM_PLANETS 8

Alien alien_selection_screen(char* planet_terrain , int count)
{
    Alien* aliens = generate_aliens(planet_terrain ,NUM_ALIENS);

    int selected = input_aliens(aliens, count);

    return aliens[selected];
}

Planet map_screen()
{
    Planet* planets = generate_planet(NUM_PLANETS);
    if (!planets)
    {
        printf("Failed to generate planets.\n");
        exit(1);
    }

    
    const char* terrain_ptrs[NUM_PLANETS];
    double planet_distances[NUM_PLANETS];

    for (int i = 0; i < NUM_PLANETS; i++)
    {
        terrain_ptrs[i] = planets[i].name;
        planet_distances[i] = planets[i].distance;

    }

    int selected_planet = input_text(terrain_ptrs, NUM_PLANETS);
    if (selected_planet == -1)
    {
        printf("Planet selection canceled.\n");
        free(planets);
        return (Planet) { 0 };
    }

    Planet chosen = planets[selected_planet];
    travel_to_planet(chosen);

    free(planets);
    return chosen;
}

int main_menu_screen()
{
    int selected = input_text(main_menu_list, main_menu_num);
    return selected;
}

void app_start()
{
    srand((unsigned int)time(NULL));
    set_console_size(110, 40);
    set_console_font_size(7, 14);
    reset_console();

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
            Planet planet = map_screen();
            for (int i = 0; i < 8; i++)
            {
                printf("Navigating through deep space...\n");
                if (i % 2 == 0)
                {
                    printf("\n");
                }
                print_ship();
                hold_seconds(0.3);
                reset_console();
            }
            printg(0.025, "You have arrived at planet %s.\n", planet.name);
            hold_seconds(1);
			reset_console();
            printg(0.05, "Scanning surface...\n");
            hold_seconds(1);
            printg(0.035, "Planet %s is covered in %s terrain.\n", planet.name, planet.terrain);
            hold_seconds(2);
            reset_console();
            printg(0.05, "Life signs detected...\n");
            hold_seconds(1);
            printg(0.035, "You have discovered %d alien lifeforms on this world.\n", NUM_ALIENS);
			hold_seconds(2.5);
            selected_alien = alien_selection_screen(planet.terrain, NUM_ALIENS);
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