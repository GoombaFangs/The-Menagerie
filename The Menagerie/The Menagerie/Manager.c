#include "manager.h"

void get_aliens(alien* aliens , int count)
{
    double duration = 0.2;
    int keyboard_input;
    int default_option = on_card_start(aliens, count);
    scroll_to_line(0);
    if (hold_seconds(duration))
    {
        reset_console();
        card1_details(aliens, count);
        scroll_to_line(0);
    }
    while (1)
    {
        keyboard_input = _getch();
        if (keyboard_input == 0 || keyboard_input == 224)
        {
            keyboard_input = _getch();

            switch (keyboard_input)
            {
            case 72://Up arrow
                if (default_option == 4)
                {
                    reset_console();
                    default_option = card3(aliens, count);
                }
                else if (default_option == 3)
                {
                    reset_console();
                    default_option = card2(aliens, count);
                }
                else if (default_option == 2)
                {
                    reset_console();
                    default_option = card1(aliens, count);
                }
                scroll_to_line(0);
				break;

            case 80://Down arrow
                if (default_option == 1)
                {
                    reset_console();
                    default_option = card2(aliens, count);
                }
                else if (default_option == 2)
                {
                    reset_console();
                    default_option = card3(aliens, count);
                }
                else if (default_option == 3)
                {
                    reset_console();
                    default_option = card4(aliens, count); 
                }
                scroll_to_line(0);
                break;
            }
        }
        else if (keyboard_input == 13)// Enter
        {
            switch (default_option)
            {
			case 1://card1
                reset_console();
                break;
			case 2://card2
                reset_console();
                break;
			case 3://card3
                reset_console();
                break;
			case 4://card4
                reset_console();
                break;
            }
        }

        if (hold_seconds(duration))
        {
            if (default_option == 1)
            {
                reset_console();
                card1_details(aliens, count);
                scroll_to_line(0);
            }

            if (default_option == 2)
            {
                reset_console();
                card2_details(aliens, count);
                scroll_to_line(0);
            }

            if (default_option == 3)
            {
                reset_console();
                card3_details(aliens, count);
                scroll_to_line(0);
            }

            if (default_option == 4)
            {
                reset_console();
                card4_details(aliens, count);
                scroll_to_line(0);
            }
        }
    }
    free(aliens);
}

int open_map()
{
    int num_planets = 4; 
    planet* planets = generate_planet(num_planets);

    const char** terrain_ptrs = malloc(num_planets * sizeof(char*));
    if (!terrain_ptrs)
    {
        printf("Memory allocation failed!\n");
        free(planets);
        return -1;
    }

    for (int i = 0; i < num_planets; i++)
    {
        terrain_ptrs[i] = planets[i].terrain;
    }

    int selected = input(1, terrain_ptrs, num_planets);

    scroll_to_line(0);
    free(terrain_ptrs);
    free(planets);
    return selected;
}

int menu()
{
    int selected = input(1, menu_list, menu_num);
	return selected;    
}

void app_start()
{
   srand((unsigned int)time(NULL));
   int running = 1;
   int do_next = menu();
   int number_of_aliens = 4;
   alien* aliens = generate_aliens(number_of_aliens);
   while (running == 1)
   {
       switch (do_next)
       {
       case 0: //map
           open_map();
           break;

       case 1: //zoo
           get_aliens(aliens, number_of_aliens);
           do_next = menu();
           break;

       case 2: //inventory
           //open inventory
           break;

       case 3: //exit
           running = 0;
           break;

       default:
           break;
       }
   }
}