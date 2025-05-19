#include "manager.h"

void get_aliens(alien* aliens , int count)
{
    int keyboard_input;
    int default_option = on_card_start(aliens, count);
	double duration = 0.2;
    scroll_to_top();
    if (hold_seconds(duration))
    {
        clear_console();
        card1_details(aliens, count);
        scroll_to_top();
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
                    clear_console();
                    default_option = card3(aliens, count);
                }
                else if (default_option == 3)
                {
                    clear_console();
                    default_option = card2(aliens, count);
                }
                else if (default_option == 2)
                {
                    clear_console();
                    default_option = card1(aliens, count);
                }
                scroll_to_top();
				break;

            case 80://Down arrow
                if (default_option == 1)
                {
                    clear_console();
                    default_option = card2(aliens, count);
                }
                else if (default_option == 2)
                {
                    clear_console();
                    default_option = card3(aliens, count);
                }
                else if (default_option == 3)
                {
                    clear_console();
                    default_option = card4(aliens, count); 
                }
                scroll_to_top();
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

        if (hold_seconds(duration))
        {
            if (default_option == 1)
            {
                clear_console();
                card1_details(aliens, count);
                scroll_to_top();
            }

            if (default_option == 2)
            {
                clear_console();
                card2_details(aliens, count);
                scroll_to_top();
            }

            if (default_option == 3)
            {
                clear_console();
                card3_details(aliens, count);
                scroll_to_top();
            }

            if (default_option == 4)
            {
                clear_console();
                card4_details(aliens, count);
                scroll_to_top();
            }
        }
    }
    free(aliens);
}

int menu()
{
    int selected = input(menu_list, menu_num);
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