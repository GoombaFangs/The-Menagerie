#include "manager.h"

#define NUM_ALIENS 6
#define NUM_PLANETS 5

Alien* alien_selection_screen(char* planet_terrain, int count, int* selected_alien_index, int generate_new)
{
	static Alien* aliens = NULL;
    if (generate_new == 1)
    {
         aliens = generate_aliens(planet_terrain, NUM_ALIENS);
    }

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
    for (int i = 0; i < 4; i++)
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

    if (printg(0.05, " %s is %.1f light years away.\n", planet.name, planet.distance / 4) == -1) return -1;
    hold_seconds(1);

    for (int i = 0; i < 14; i++)
    {
		reset_console();
        printf("Scanning...\n");
        printf(" %s is %.1f light years away.\n\n", planet.name, planet.distance / 4);
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

    printg(0.05, "\nAlien is found..\n");

    hold_seconds(2);

    return 0;
}

void new_alien_screen(Planet planet, int got_alien)
{
	reset_console();
    print_planet_menu(planet.terrain);
    if (got_alien != -1)
    {
        printg(0.03, "\n YOU GOT A NEW  ALIEN\n");
    }
    print_ship_leave_planet(planet.terrain,  got_alien);
	hold_seconds(0.5);
	reset_console();
}

int ship_log_screen()
{
	int selected = 0;
    reset_console();
    const char* list[] = { "  Planet  ","  Alien   ","  Exit   " };
    selected = input_text(list, 3, 4, ""); // 4 = ship log style
    switch (selected)
    {
    case -1: // Exit
        reset_console();
        return -1;
    case 0: // Planet
        //display_planet_log();
		return 0;
        break;
    case 1: // Alien
        //display_alien_log();
        return 0;
        break;
    case 2: // Exit
        reset_console();
        return -1;
    default:
		return 0;
    }
}

void app_start()
{
    srand((unsigned int)time(NULL)); // Seed the random number generator
    set_console_size(110, 45);
    set_console_font_size(7, 14);
    reset_console();
    title();

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
            int generate_new = 1;
            alien_list = alien_selection_screen(planet.terrain, NUM_ALIENS, &selected_alien_index, generate_new);

            if (alien_list && selected_alien_index >= 0 && selected_alien_index < NUM_ALIENS)
            {
                int show_nickname_prompt = 1;
                int selected = 1;

                do
                {
                    alien_list[selected_alien_index] = add_nickname(alien_list, selected_alien_index, &backspace, &selected);

                    if (backspace == -1)
                    {
						alien_list[selected_alien_index].nickname[0] = '\0'; // Clear nickname
                        const char* list[] = {"  Continue  ","  Back   ","  Exit   "};
                         selected = input_text(list, 3, 1, planet.terrain); // 1 = planet terrain style

						 switch (selected)
                         {
						 case 1: // Back
                             alien_list = alien_selection_screen(planet.terrain, NUM_ALIENS, &selected_alien_index , generate_new = 0);
							 break;
                         case 2: // Exit
                             do_next = -1;
                             show_nickname_prompt = 0;
                             break;
                         }
                    }
                    else
                    {
                        show_nickname_prompt = 0;
                    }

                } while (show_nickname_prompt);
            }
			else if (selected_alien_index == -1)
			{
				do_next = -1;
			}

			if (do_next != -1)
			{
                alien_card(alien_list, selected_alien_index);
                hold_seconds(2);
                reset_console();
			}

            new_alien_screen(planet, do_next);

            if (alien_list != NULL && selected_alien_index >= 0 && selected_alien_index < NUM_ALIENS)
            {
                add_alien_to_zoo(alien_list[selected_alien_index]);
                free(alien_list);
                alien_list = NULL;
            }

            do_next = -1;
            break;
        }
        case 1://zoo
        {
            int selected = display_zoo();
			reset_console();
            do_next = selected;
            break;
        }

        case 2: //Ship log
        {
            int selected = ship_log_screen();
            do_next = selected;
            break;
        }
        case 3: //exit
            running = 0;
            break;

        default:
            do_next = -1;
            break;
        }
    }
}