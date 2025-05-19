#include "manager.h"

void get_aliens(Alien* aliens , int count)
{
    int keyboard_input;
    int default_option = on_card_start(aliens, count);
	int lines_to_scroll = 5;
    scroll_to_top();
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
					clear_console();
                    scroll_to_up(lines_to_scroll);
                    default_option = on_card3(aliens, count);
                }
                else if (default_option == 3)
                {
                    clear_console();
                    scroll_to_up(lines_to_scroll);
                    default_option = on_card2(aliens, count);
                }
                else if (default_option == 2)
                {
                    clear_console();
                    default_option = on_card1(aliens, count);
                    scroll_to_top();
                }
                break;
            case 80://Down arrow
                if (default_option == 1)
                {
                    clear_console();
                    scroll_to_down(lines_to_scroll);
                    default_option = on_card2(aliens, count);
                }
                else if (default_option == 2)
                {
                    clear_console();
                    scroll_to_down(lines_to_scroll);
                    default_option = on_card3(aliens, count);
                }
                else if (default_option == 3)
                {
                    clear_console();
                    scroll_to_down(lines_to_scroll);
                    default_option = on_card4(aliens, count);
                }
                break;
            }
        }
        else if (keyboard_input == 13)// Enter
        {
            switch (default_option)
            {
			case 1://card1
                clear_console();
                return 0;
                break;
			case 2://card2
                clear_console();
                return 1;
                break;
			case 3://card3
                clear_console();
                return 2;
                break;
			case 4://card4
                clear_console();
                return 3;
                break;
            }
        }
    }
    //free(aliens);
}

int menu()
{
    int keyboard_input;
    int default_option = on_start();
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
                    default_option = on_inventory();
                }
                else if (default_option == 3)
                {
                    default_option = on_zoo();
                }
                else if (default_option == 2)
                {
                    default_option = on_map();
                }
                break;
            case 80://Down arrow
                if (default_option == 1)
                {
                    default_option = on_zoo();
                }
                else if (default_option == 2)
                {
                    default_option = on_inventory();
                }
				else if (default_option == 3)
				{
					default_option = on_exit();
				}
                break;
            }
        }
		else if (keyboard_input == 13)// Enter
		{
			switch (default_option)
			{
			case 1://Map
				clear_console();
				return 0;
				break;
			case 2://Zoo
				clear_console();
				return 1;
				break;
			case 3://Inventory
				clear_console();
				return 2;
				break;
			case 4://Exit
				clear_console();
				return 3;
				break;
			}
		}
    }
}

void app_start()
{
   srand((unsigned int)time(NULL));
   int running = 1;
   int do_next = menu();
   int number_of_aliens = 4;
   Alien* aliens = generate_aliens(number_of_aliens);
   while (running == 1)
   {
       switch (do_next)
       {
       case 0: //map
           //open map
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