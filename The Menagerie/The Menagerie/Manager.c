#include "manager.h"

void get_aliens(int count)
{
    Alien* aliens = generate_aliens(count);

    for (int i = 0; i < count; i++)
    {
        print_alien_art(&aliens[i], i);
    }

    for (int i = 0; i < count; i++)
    {
        print_alien_card(&aliens[i], i);
    }
    free(aliens);
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
                if (default_option == 3)
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
                break;
            }
        }
        else if (keyboard_input == 13)
        {
            switch (default_option)
            {
            case 1://Play
                clear_console();
                return 1;
                break;

            case 2://LeaderBoard
                clear_console();
                return 2;
                break;

            case 3://Exit
                clear_console();
                return 3;

            }
        }
    }
}

void app_start()
{
   srand((unsigned int)time(NULL));
   int running = 1;
   int do_next = menu();
   while (running == 1)
   {
       switch (do_next)
       {
       case 0: //map
		   get_aliens(5);
           //open map
           break;

       case 1: //zoo
           //open zoo
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