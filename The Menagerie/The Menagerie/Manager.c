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

    const char* planet_names[NUM_PLANETS];
    for (int i = 0; i < NUM_PLANETS; i++)
    {
        planet_names[i] = planets[i].name;
    }

    int selected = input_text(planet_names, NUM_PLANETS, 3, ""); // 3 = star map style
    if (selected == -1)
    {
        free(planets);
        return (Planet) { 0 };
    }

    Planet chosen;
    memcpy(&chosen, &planets[selected], sizeof(Planet)); // Create a proper copy

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

int ship_log_screen(const Zoo* zoo)
{
	int selected = 0;
    reset_console();
    const char* list[] = { "  Planet  ","  Alien   ","  Back   " };
    selected = input_text(list, 3, 4, ""); // 4 = ship log style
    switch (selected)
    {
    case -1: // Exit
        reset_console();
        return -1;

    case 0: // Planet
        planet_log();
		return 2;
        break;

    case 1: // Alien
        alien_log(zoo);
        return 2;
        break;

    case 2: // Exit
        reset_console();
        return -1;
    default:
        return -1;
    }
}

int explore_planet(Zoo* zoo)
{
    Planet planet = map_screen();
    if (planet.name[0] == '\0' || story_screen(planet) == -1)
    {
        return -1;
    }

    int selected_alien_index;
    int backspace = 0;
    int generate_new = 1;

    Alien* alien_list = alien_selection_screen(planet.terrain, NUM_ALIENS, &selected_alien_index, generate_new);

    if (alien_list && selected_alien_index >= 0 && selected_alien_index < NUM_ALIENS)
    {
        int show_nickname_prompt = 1;
        int menu_choice = 1;

        do
        {
            alien_list[selected_alien_index] = add_nickname(alien_list, selected_alien_index, &backspace);

            if (backspace == -1)
            {
                alien_list[selected_alien_index].nickname[0] = '\0';
                const char* list[] = { "  Continue  ", "  Back   ", "  Exit   " };
                menu_choice = input_text(list, 3, 1, planet.terrain);

                switch (menu_choice)
                {
                case 1:
                    generate_new = 0;
                    alien_list = alien_selection_screen(planet.terrain, NUM_ALIENS, &selected_alien_index, generate_new);
                    if (selected_alien_index == -1)
                    {
                        return -1;
                    } 
                    break;
                case 2:
                    return -1;
                }
            }
            else
            {
                show_nickname_prompt = 0;
            }

        } while (show_nickname_prompt);
    }
    else
    {
        return -1;
    }

    alien_card(alien_list, selected_alien_index);
    hold_seconds(2);
    reset_console();
    new_alien_screen(planet, 0);

    if (selected_alien_index >= 0 && backspace != -1)
    {
        add_alien_to_zoo(zoo, alien_list[selected_alien_index]);
        save_aliens_to_file(zoo);

        add_planet_visit(planet, alien_list[selected_alien_index]);
    }

    free(alien_list);
    return -1;
}

void app_start()
{
    srand((unsigned int)time(NULL)); // Seed the random number generator
    set_console_size(110, 45);
    set_console_font_size(7, 14);
    reset_console();
    title();

    Zoo zoo = { NULL, 0, 0 };
    load_planet_visits_from_file();
    load_aliens_from_file(&zoo);

    int running = 1;
    int do_next = -1;

    while (running)
    {
        switch (do_next)
        {
		case -1: // Return to main menu
            do_next = main_menu_screen();
            break;

        case 0:// Map
            do_next = explore_planet(&zoo);
            save_planet_visits_to_file();
            break;

		case 1: // Zoo
            do_next = input_zoo(&zoo);
            reset_console();
            break;

		case 2: //Ship log
            do_next = ship_log_screen(&zoo);
            break;

		case 3: //Exit
            free_zoo(&zoo);
            running = 0;
            break;

        default:
            do_next = -1;
            break;
        }
    }
}