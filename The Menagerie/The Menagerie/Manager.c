#include "manager.h"

#define NUM_ALIENS 6
#define NUM_PLANETS 5

Alien* alien_selection_screen(char* planet_terrain , int count ,int* selected_alien_index)
{
    Alien* aliens = generate_aliens(planet_terrain ,NUM_ALIENS);

    int selected = input_aliens(planet_terrain, aliens, count);

    if (selected_alien_index != NULL)
    {
        *selected_alien_index = selected;
    }
    return aliens;
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

    for (int i = 0; i < NUM_PLANETS; i++)
    {
        terrain_ptrs[i] = planets[i].name;
    }

	int selected_planet = input_text(terrain_ptrs, NUM_PLANETS, 3, "");//3 = Star map style
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
    for (int i = 0; i < 2; i++)
    {
        if (i % 2 == 0) printf("\n");

        print_ship();
        hold_seconds(0.3);
        reset_console();
    }
    int selected = input_text(main_menu_list, main_menu_num, 2, "");//2 = space windows style
    return selected;
}

int story_screen(Planet planet)
{
    if (printg(0.05, "Scanning...\n") == -1) return -1;
    hold_seconds(1);

    if (printg(0.05, "%s is %.1f light years away.\n", planet.name, planet.distance / 4) == -1) return -1;
    hold_seconds(1);

    for (int i = 0; i < 14; i++)
    {
        printf("\n   Navigating through deep space...\n\n");
        if (i % 2 == 0) printf("\n");

        print_ship();
        hold_seconds(0.3);
        reset_console();
    }
	print_ship_arrive_planet(planet.terrain);

    if (printg(0.0005, "                                            You have arrived at planet %s.\n", planet.name) == -1) return -1;
    hold_seconds(1);

    if (printg(0.05, "\n\n\nScanning surface...\n") == -1) return -1;
    hold_seconds(1);
    if (printg(0.3, ".....\n") == -1) return -1;

    if (printg(0.04, "Planet %s is covered in %s terrain.\n", planet.name, planet.terrain) == -1) return -1;
    hold_seconds(2.2);

    reset_console();

    printg(0.05, "Life signs detected...\n");
    hold_seconds(1.5);

    return 0;
}

void key_binding_screen()
{
    printg(0.045, "Press Up or Down arrow ,  Enter to confirm , Escape to go back\n\n");
	hold_seconds(2);
}

void app_start()
{
    srand((unsigned int)time(NULL)); // Seed the random number generator
    set_console_size(110, 40);
    set_console_font_size(7, 14);
    reset_console();
    key_binding_screen();
    load_zoo_from_file("zoo.txt");

    int running = 1;
    int do_next = main_menu_screen();
    Alien* alien_list = NULL;

    while (running)
    {
        switch (do_next)
        {
        case -1: // return to menu
            do_next = main_menu_screen();
            break;

        case 0: // Explore Planet
        {
            if (printg(0.02, "Choose your next destination among the stars..\n") == -1)
            {
                do_next = -1;
                break;
            }
            hold_seconds(1.2);
            Planet planet = map_screen();
            if (planet.name[0] == '\0')//Exit while choosing planet
            {
                do_next = -1;
                break;
            }
            else if (story_screen(planet) == -1)//Exit while the story is running
            {
                do_next = -1;
                break;
            }

            int selected_alien_index;
            int backspace;
            alien_list = alien_selection_screen(planet.terrain, NUM_ALIENS, &selected_alien_index);

            if (alien_list && selected_alien_index >= 0 && selected_alien_index < NUM_ALIENS)
            {
                int show_nickname_prompt = 1;

                do
                {
                    alien_list[selected_alien_index] = add_nickname(alien_list, selected_alien_index, &backspace);

                    if (backspace == -1)
                    {
						alien_list[selected_alien_index].nickname[0] = '\0'; // Clear nickname
                        const char* list[] = { "  Continue  ", "  Exit   " };
                        int selected = input_text(list, 2, 1, planet.terrain); // 1 = planet terrain style

                        if (selected != 0)
                        {
                            do_next = -1;
                            break;
                        }
                    }
                    else
                    {
                        show_nickname_prompt = 0;
                    }

                } while (show_nickname_prompt);
            }

			if (do_next != -1)
			{
                alien_card(alien_list, selected_alien_index);
                
                hold_seconds(2);
                reset_console();
			}
            add_alien_to_zoo(alien_list[selected_alien_index]);
            save_zoo_to_file("zoo.txt");
            free(alien_list);
            alien_list = NULL;

            do_next = -1;
            break;
        }
        case 1: //zoo
            display_zoo();
            hold_seconds(5);
            do_next = -1;
            break;

        case 2: //Ship log
            do_next = -1;
            // TODO: open Ship log
            break;

        case 3: //exit
            running = 0;
            break;

        default:
            do_next = -1;
            break;
        }
    }
}